#ifndef __SOTR_H__
#define __SOTR_H__

typedef int sort_fountion_t(int *, long long int);

int sort_data(int *arr, long long int len, sort_fountion_t *func[]);
int bubbleSort(int *arr, long long int len);
int selectionSort(int *arr, long long int len);
int insertionSort(int *arr, long long int len);
int shellSort(int *arr, long long int len);
int merge_sort(int *arr, long long int len);
int quickSort(int *arr, long long int len);
int quickSort2(int *arr, long long int len);
int HeapSort(int *arr, long long int len);
int CountingSort(int *arr, long long int len);
int bucketSort(int *arr, long long int len);
#endif //__SOTR_H__
