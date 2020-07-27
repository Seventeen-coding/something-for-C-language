#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sort.h"
#include "test_time.h"
#include "log_util.h"

// #define SORT_DEBUG

int sort_data(int *arr, long long int len, sort_fountion_t *func[])
{
#ifdef SORT_DEBUG
    PRINT_DATA(arr, len);

    int *input = malloc(sizeof(int) * len);
    if (input == NULL)
    {
        return -1;
    }
    int i = 0;
    printf("data_len:%ld \n", len);
    while (func[i] != NULL)
    {
        memcpy(input, arr, sizeof(int) * len);
        TEST_TIME(func[i](input, len));
        i++;
    }
    PRINT_DATA(input, len);
    free(input);
#else
    int *input = arr;
    printf("sort:");
    TEST_TIME(func[0](input, len));
#endif

    return 0;
}

int bubbleSort(int *arr, long long int len)
{

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {                          // 相邻元素两两对比
                int temp = arr[j + 1]; // 元素交换
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return 0;
}
/*
int *radixSort(int *arr, long long int len, int maxDigit)
{
    static int counter[1024];
    int mod = 10;
    int dev = 1;
    for (int i = 0; i < maxDigit; i++, dev *= 10, mod *= 10)
    {
        for (int j = 0; j < len; j++)
        {
            int bucket = parseInt((arr[j] % mod) / dev);
            if (counter[bucket] == null)
            {
                counter[bucket] = [];
            }
            counter[bucket].push(arr[j]);
        }
        int pos = 0;
        for (int j = 0; j < counter.length; j++)
        {
            int value = null;
            if (counter[j] != null)
            {
                while ((value = counter[j].shift()) != null)
                {
                    arr[pos++] = value;
                }
            }
        }
    }
    return arr;
}
*/
int selectionSort(int *arr, long long int len)
{
    int minIndex, temp;
    for (int i = 0; i < len - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIndex])
            {                 // 寻找最小的数
                minIndex = j; // 将最小数的索引保存
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    return 0;
}

int insertionSort(int *arr, long long int len)
{
    int preIndex, current;
    for (int i = 1; i < len; i++)
    {
        preIndex = i - 1;
        current = arr[i];
        while (preIndex >= 0 && arr[preIndex] > current)
        {
            arr[preIndex + 1] = arr[preIndex];
            preIndex--;
        }
        arr[preIndex + 1] = current;
    }
    return 0;
}

int shellSort(int *arr, long long int len)
{
    int temp, gap = 1;
    while (gap < len / 3)
    { //动态定义间隔序列
        gap = gap * 3 + 1;
    }
    for (gap; gap > 0; gap /= 3)
    {
        for (int i = gap; i < len; i++)
        {
            temp = arr[i];
            int j = 0;
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
            {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }
    return 0;
}

//归并 start
/* 
函数功能：合并
函数参数：
 arr: 目标数组
 start: 待合并段开始下标
 mid: 待合并段中间下标
 end: 待合并段结束下标
 */
int merge(int *arr, long long int start, long long int mid, long long int end)
{
    long long int len_l, len_r; //左右待合并区间的长度
    len_l = mid - start + 1;
    len_r = end - mid;
    int l[len_l], r[len_r]; //gcc, 两个临时数组，分别保存待合并的两个区间
    //int l[100], r[100]; //vc
    memcpy(l, arr + start, sizeof(int) * len_l);
    memcpy(r, arr + mid + 1, sizeof(int) * len_r);

    long long int i = 0, j = 0, k = start;
    while (i < len_l && j < len_r)
    {
        arr[k++] = l[i] < r[j] ? l[i++] : r[j++];
    }

    while (i < len_l)
    {
        arr[k++] = l[i++];
    }
    return 0;
}
/* 
函数功能：归并排序
函数参数：
 arr: 待排序的数组
 start: 待排序数组开始下标
 end: 待排序数组结束下标
 */
int merge_sort_ex(int *arr, long long int start, long long int end)
{
    if (start < end)
    {
        long long int mid = (start + end) / 2;
        //归
        merge_sort_ex(arr, start, mid);
        merge_sort_ex(arr, mid + 1, end);
        //并
        merge(arr, start, mid, end);
    }
    return 0;
}
int merge_sort(int *arr, long long int len)
{
    return merge_sort_ex(arr, 0, len);
}
//归并 end
//快速排序 start
static int swap(int *arr, long long int i, long long int j);
static int partition(int *arr, long long int left, long long int right);
static int quickSort_ex(int *arr, long long int len, long long int left, long long int right);

int quickSort(int *arr, long long int len)
{
    return quickSort_ex(arr, len, 0, len);
}
static int quickSort_ex(int *arr, long long int len, long long int left, long long int right)
{
    if (left < right)
    {
        int partitionIndex = partition(arr, left, right);
        quickSort_ex(arr, len, left, partitionIndex - 1);
        quickSort_ex(arr, len, partitionIndex + 1, right);
    }
    return 0;
}

static int partition(int *arr, long long int left, long long int right)
{                     // 分区操作
    int pivot = left, // 设定基准值（pivot）
        index = pivot + 1;
    for (int i = index; i <= right; i++)
    {
        if (arr[i] < arr[pivot])
        {
            swap(arr, i, index);
            index++;
        }
    }
    swap(arr, pivot, index - 1);
    return index - 1;
}

static int swap(int *arr, long long int i, long long int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return 0;
}

static void quickSort2_ex(int *arr, long long int lo, long long int hi);
int quickSort2(int *arr, long long int len)
{
    quickSort2_ex(arr, 0, len);
}
void quickSort2_ex(int *arr, long long int lo, long long int hi)
{
    if (hi - lo < 2)
        return;

    //交换序列 中间元素 与 首元素，使中间元素为“基准”元素
    int temp = arr[(lo + hi) >> 1];
    arr[(lo + hi) >> 1] = arr[lo];
    arr[lo] = temp;

    long long int _lo = lo, _hi = hi;
    int key = arr[lo];

    while (1)
    {
        while (arr[++_lo] < key && _lo < hi)
            ; //向右找≥key的元素
        while (arr[--_hi] > key && _hi > lo)
            ; //向左找≤key的元素
        if (_lo >= _hi)
            break; //_lo与_hi相交时结束循环
        temp = arr[_lo];
        arr[_lo] = arr[_hi];
        arr[_hi] = temp; //交换_lo,_hi对应的值
    }
    temp = arr[_hi];
    arr[_hi] = key;
    arr[lo] = temp; //“基准”值与_hi对应值交换
    /*  为什么与 _hi 对应的值交换呢？  
           1、基于升序排列
           2、把基准元素放到了前面
          条件1，2 决定了 基准元素的位置 应该存放比基准元素 小 或者 等 的元素，
          而 _hi 只有遇到 <= 基准元素 的元素时才会停下！ 即 _hi 最终指向<= 基准元素 的元素
    */
    quickSort2_ex(arr, lo, _hi);
    quickSort2_ex(arr, _hi + 1, hi);
}

//快速排序 end

//堆排 start
static void heapify(int *arr, long long int i, long long int len);
static void buildMaxHeap(int *arr, long long int len);
int HeapSort(int *arr, long long int len)
{
    buildMaxHeap(arr, len);

    for (int i = len - 1; i > 0; i--)
    {
        swap(arr, 0, i);
        len--;
        heapify(arr, 0, len);
    }
    return 0;
}

void buildMaxHeap(int *arr, long long int len)
{
    for (long long int i = len / 2; i >= 0; i--)
    {
        heapify(arr, i, len);
    }
}

void heapify(int *arr, long long int i, long long int len)
{
    long long int left = 2 * i + 1;
    long long int right = 2 * i + 2;
    long long int largest = i;

    if (left < len && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < len && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr, i, largest);
        heapify(arr, largest, len);
    }
}

//堆排end

//计数排序 start
static long long int getMaxValue(int *arr, long long int len);
static int countingSort(int *arr, long long int len, int maxValue);
int CountingSort(int *arr, long long int len)
{
    long long int maxValue = getMaxValue(arr, len);

    return countingSort(arr, len, maxValue);
}

int countingSort(int *arr, long long int len, int maxValue)
{
    long long int bucketLen = maxValue + 1;
    long long int *bucket = malloc(sizeof(long long int) * bucketLen);
    if (bucket == NULL)
    {
        return -1;
    }
    for (long long int i = 0; i < len; i++)
    {
        bucket[arr[i]]++;
    }

    int sortedIndex = 0;
    for (int j = 0; j < bucketLen; j++)
    {
        while (bucket[j] > 0)
        {
            arr[sortedIndex++] = j;
            bucket[j]--;
        }
    }
    if (bucket != NULL)
    {
        free(bucket);
        bucket = NULL;
    }
    return 0;
}

long long int getMaxValue(int *arr, long long int len)
{
    long long int maxValue = arr[0];
    for (long long int i = 0; i < len; i++)
    {
        if (maxValue < arr[i])
        {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

//计数排序 end

//桶排序 start
static int bucket_sort(int keys[], long long int size, int bucket_size);
int bucketSort(int *arr, long long int len)
{
    return bucket_sort(arr, len, 1024);
}

typedef struct node
{
    long long int key;
    struct node *next;
} KeyNode;

int bucket_sort(int keys[], long long int size, int bucket_size)
{
    long long int i, j;
    KeyNode **bucket_table = (KeyNode **)malloc(bucket_size * sizeof(KeyNode *));
    for (i = 0; i < bucket_size; i++)
    {
        bucket_table[i] = (KeyNode *)malloc(sizeof(KeyNode));
        bucket_table[i]->key = 0;
        bucket_table[i]->next = NULL;
    }
    for (j = 0; j < size; j++)
    {
        KeyNode *node = (KeyNode *)malloc(sizeof(KeyNode));
        node->key = keys[j];
        node->next = NULL;
        long long int index = keys[j] / 10;
        KeyNode *p = bucket_table[index];
        if (p->key == 0)
        {
            bucket_table[index]->next = node;
            (bucket_table[index]->key)++;
        }
        else
        {
            while (p->next != NULL && p->next->key <= node->key)
                p = p->next;
            node->next = p->next;
            p->next = node;
            (bucket_table[index]->key)++;
        }
    }

    // KeyNode *k = NULL, *tmp = k;
    // int *p = keys;
    // for (i = 0; i < bucket_size; i++)
    //     for (k = bucket_table[i]->next; k != NULL; tmp = k, k = k->next, free(tmp))
    //     {
    //         *p = k->key;
    //         p = p + 1;
    //     }

    // if (bucket_table != NULL)
    // {
    //     free(bucket_table);
    // }
    return 0;
}
//桶排序 end