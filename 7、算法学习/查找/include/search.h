#ifndef __SEARCH_H__
#define __SEARCH_H__

typedef long long int search_fountion_t(int *, long long int, int *, long long int, long long int *, long long int);

int search_data(int *arr, long long int len, int *values, long long int v_len, search_fountion_t *func[]);
long long int SequenceSearch(int *a, long long int a_len, int *values, long long int v_len, long long int *result, long long int result_len);
long long int Binary_Search(int *a, long long int a_len, int *values, long long int v_len, long long int *result, long long int result_len);
long long int Binary_Search2(int *a, long long int a_len, int *values, long long int v_len, long long int *result, long long int result_len);
long long int FibonacciSearch(int *a, long long int a_len, int *values, long long int v_len, long long int *result, long long int result_len);
#endif //__SEARCH_H__