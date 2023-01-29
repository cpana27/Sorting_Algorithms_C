#ifndef SORTING_ALGORITHM_H
#define SORTING_ALGORITHM_H

int *BubbleSort(int *array, int size);
void InsertionSort(int *array, int size);
void SelectionSort(int *array, int size);
void MergeSort(int *array, int left, int right);
int Partition(int *array, int left, int right);
void QuickSort(int *array, int left, int right);
void HeapSort(int *array, int size);
void Heapify(int *array, int size, int i);
void CountingSort(int *array, int size);
void RadixSort(int *array, int size);
void BucketSort(int *array, int size);

#endif // SORTING_ALGORITHM_H