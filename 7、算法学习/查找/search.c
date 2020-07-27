

#include <stdlib.h>
#include <string.h>
#include "log_util.h"
#include "search.h"
#include "test_time.h"
#include "sort.h"
#define SEARCH_DEBUG

int search_data(int *arr, long long int len, int *values, long long int v_len, search_fountion_t *func[])
{
#ifdef SEARCH_DEBUG

    int *input = NULL;
    long long int *reslut = NULL;
    input = malloc(sizeof(int) * len);
    reslut = malloc(sizeof(long long int) * v_len);
    long long int count = 0;
    int i = 0;
    while (func[i] != NULL)
    {
        printf("---------------%d---------------\n", i + 1);
        memset(reslut, 0, sizeof(long long int) * v_len);
        memcpy(input, arr, sizeof(int) * len);
        printf("---before search input\n");
        PRINT_DATA(input, len > 64 ? 64 : len);
        TEST_TIME({
            count = func[i](input, len, values, v_len, reslut, v_len);
            printf("search:");
        });
        printf("---after search input\n");
        PRINT_DATA(input, len > 64 ? 64 : len);
        printf("----values:\n");
        PRINT_DATA(values, v_len > 64 ? 64 : v_len);
        printf("----find_values_index: find count:%ld \n", count);
        PRINT_DATA(reslut, v_len > 64 ? 64 : v_len);
        i++;
    }

    if (input != NULL)
    {
        free(input);
        input = NULL;
    }
#else
    int *input = arr;
    func[0](input, len);
#endif
    return 0;
}
//顺序查找
long long int SequenceSearch_ex(int *a, long long int a_len, int value)
{
    for (long long int i = 0; i < a_len; i++)
    {
        if (a[i] == value)
        {
            return i;
        }
    }

    return -1;
}
long long int SequenceSearch(int *a, long long int a_len, int *values, long long int v_len, long long int *result, long long int result_len)
{
    long long int count = 0;
    for (long long int j = 0; j < v_len; j++)
    {
        result[j] = SequenceSearch_ex(a, a_len, values[j]);
        if (result[j] != -1)
            count++;
    }

    return count;
}
//
//二分法
static long long int Binary_Search_ex(int *a, long long int a_len, int value);
static long long int Binary_Search2_ex(int *a, long long int a_len, int value);
long long int Binary_Search(int *a, long long int a_len, int *values, long long int v_len, long long int *result, long long int result_len)
{
    long long int count = 0;
    sort_fountion_t *sotr_util[] = {quickSort2, NULL};
    sort_data(a, a_len, sotr_util);
    for (long long int j = 0; j < v_len; j++)
    {
        result[j] = Binary_Search_ex(a, a_len, values[j]);
        if (result[j] != -1)
            count++;
    }
    return count;
}

long long int Binary_Search_ex(int *a, long long int a_len, int value)
{
    long long int low, high, mid;
    low = 0;
    high = a_len - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2; //怕high+low溢出，采用这个写法
        if (a[mid] < value)
            low = mid + 1;
        else if (a[mid] > value)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
long long int Binary_Search2(int *a, long long int a_len, int *values, long long int v_len, long long int *result, long long int result_len)
{
    long long int count = 0;
    sort_fountion_t *sotr_util[] = {quickSort2, NULL};
    sort_data(a, a_len, sotr_util);
    for (long long int j = 0; j < v_len; j++)
    {
        printf("j:%d\n", j);
        result[j] = Binary_Search2_ex(a, a_len, values[j]);
        if (result[j] != -1)
            count++;
    }
    return count;
}

long long int Binary_Search2_ex(int *a, long long int a_len, int value)
{
    long long int low, high, mid;
    low = 0;
    high = a_len - 1;
    while (low <= high)
    {
        mid = low + (value - a[low]) / ((a[high] - a[low]) * 1.0f) * (high - low); // 这里有问题
        if (a[mid] < value)
            low = mid + 1;
        else if (a[mid] > value)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

//斐波那契查找
/*构造一个斐波那契数组*/
static long long int FibonacciSearch_ex(int *a, long long int n, int key, long long int *F);
void Fibonacci(long long int *F, long long int max_size)
{
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < max_size; ++i)
        F[i] = F[i - 1] + F[i - 2];
}

long long int FibonacciSearch(int *a, long long int a_len, int *values, long long int v_len, long long int *result, long long int result_len)
{
    long long int count = 0;
    sort_fountion_t *sotr_util[] = {quickSort2, NULL};
    sort_data(a, a_len, sotr_util);
    long long int *F = malloc(sizeof(long long int) * a_len);

    Fibonacci(F, a_len);
    for (long long int j = 0; j < v_len; j++)
    {
        result[j] = FibonacciSearch_ex(a, a_len, values[j], F);
        if (result[j] != -1)
            count++;
    }
    free(F);
    return count;
}

/*定义斐波那契查找法*/
long long int FibonacciSearch_ex(int *a, long long int n, int key, long long int *F) //a为要查找的数组,n为要查找的数组长度,key为要查找的关键字
{
    long long int low = 0;
    long long int high = n - 1;

    long long int k = 0;
    while (n > F[k] - 1) //计算n位于斐波那契数列的位置
        ++k;

    while (low <= high)
    {
        int mid = low + F[k - 1] - 1;
        if (key < a[mid])
        {
            high = mid - 1;
            k -= 1;
        }
        else if (key > a[mid])
        {
            low = mid + 1;
            k -= 2;
        }
        else
        {
            if (mid < n)
                return mid; //若相等则说明mid即为查找到的位置
            else
                return n - 1; //若mid>=n则说明是扩展的数值,返回n-1
        }
    }
    return -1;
}
