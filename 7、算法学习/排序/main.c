#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define RANDOM_INT(x, y) ({ x + rand() % (y - x); })
#define RANDOM_FLOAT(x, y) ({ x + 1.0 * rand() / RAND_MAX *(y - x); })

int main(void)
{
    srand((unsigned)time(NULL));
    // int test_data_int_rand[] = {RANDOM_INT(1, 100), RANDOM_INT(1, 100), RANDOM_INT(1, 100), RANDOM_INT(1, 100), RANDOM_INT(1, 100), RANDOM_INT(1, 100)};
    float test_data_float_rand[] = {RANDOM_FLOAT(0, 10), RANDOM_FLOAT(1, 2), RANDOM_FLOAT(1, 2), RANDOM_FLOAT(1, 2), RANDOM_FLOAT(1, 2)};

    // int len = 1024 * 1000 * 100; // 亿级别
    // int len = 1024 * 1000 * 10; // 千万级别
    int len = 1024 * 100; //排序分界点十万级别
    // int len = 1024; //打印数据 看排序是否正确
    int *test_big_data_int_rand = NULL;
    {
        test_big_data_int_rand = malloc(len * sizeof(int));
        if (test_big_data_int_rand == NULL)
        {
            return -1;
        }
        for (long long int i = 0; i < len; i++)
        {
            // test_big_data_int_rand[i] = RANDOM_INT(-1024 * 10, 1024 * 10);
            test_big_data_int_rand[i] = RANDOM_INT(0, 1024 * 10);
        }
    }
    // for (int i = 0; i < sizeof(test_data_int_rand) / sizeof(int); i++)
    // {
    //     printf("%d ", test_data_int_rand[i]);
    // }
    // printf("\n");
    // for (i = 0; i < sizeof(test_data_float_rand) / sizeof(float); i++)
    // {
    //     printf("%f ", test_data_float_rand[i]);
    // }
    // printf("\n");

    sort_fountion_t *sotr_util[] = {bucketSort, NULL};
    // sort_fountion_t *sotr_util[] = {shellSort, quickSort2, NULL};
    // sort_fountion_t *sotr_util[] = {bubbleSort, selectionSort, insertionSort, shellSort, merge_sort, quickSort, NULL};
    sort_data(test_big_data_int_rand, len, sotr_util);

    if (test_big_data_int_rand != NULL)
    {
        free(test_big_data_int_rand);
        test_big_data_int_rand = NULL;
    }
    return 0;
}
