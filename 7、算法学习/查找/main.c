#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "log_util.h"

#define RANDOM_INT(x, y) ({ x + rand() % (y - x); })
#define RANDOM_FLOAT(x, y) ({ x + 1.0 * rand() / RAND_MAX *(y - x); })

int main(void)
{
    break_point("test start \n");
    srand((unsigned)time(NULL));
    // int test_data_int_rand[] = {RANDOM_INT(0, 1024 * 10), RANDOM_INT(0, 1024 * 10), RANDOM_INT(0, 1024 * 10), RANDOM_INT(0, 100), RANDOM_INT(0, 100), RANDOM_INT(0, 100)};
    float test_data_float_rand[] = {RANDOM_FLOAT(0, 10), RANDOM_FLOAT(1, 2), RANDOM_FLOAT(1, 2), RANDOM_FLOAT(1, 2), RANDOM_FLOAT(1, 2)};

    int len = 1024 * 1000 * 100; // 亿级别
    // int len = 1024 * 1000 * 10; // 千万级别
    // int len = 1024 * 100; //排序分界点十万级别
    // int len = 1024; //打印数据 看排序是否正确
    // int len = 100; //打印数据 看排序是否正确
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
            test_big_data_int_rand[i] = RANDOM_INT(0, 1024 * 100);
        }
    }
    int len2 = 64 * 100;
    // int len2 = 64;
    int *test_data_int_rand = NULL;
    {
        test_data_int_rand = malloc(len2 * sizeof(int));
        if (test_data_int_rand == NULL)
        {
            return -1;
        }
        for (long long int i = 0; i < len2; i++)
        {
            test_data_int_rand[i] = RANDOM_INT(-1024 * 10, 1024 * 100);
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

    search_fountion_t *search_util[] = {Binary_Search, FibonacciSearch, NULL};
    // search_fountion_t *search_util[] = {SequenceSearch, Binary_Search, Binary_Search2, NULL};
    // search_data(test_big_data_int_rand, len, test_data_int_rand, sizeof(test_data_int_rand) / sizeof(int), search_util);
    search_data(test_big_data_int_rand, len, test_data_int_rand, len2, search_util);

    if (test_big_data_int_rand != NULL)
    {
        free(test_big_data_int_rand);
        test_big_data_int_rand = NULL;
    }
    break_point("test end \n");
    return 0;
}
