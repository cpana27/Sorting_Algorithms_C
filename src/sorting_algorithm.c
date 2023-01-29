#include "sorting_algorithm.h"
#include "utils.h"

int *BubbleSort(int *array, int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array;
}

void InsertionSort(int *array, int size)
{
    int i, j, temp;
    for (i = 1; i < size; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

void SelectionSort(int *array, int size)
{
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void Merge(int *array, int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = array[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = array[middle + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int *array, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        MergeSort(array, left, middle);
        MergeSort(array, middle + 1, right);
        Merge(array, left, middle, right);
    }
}

int Partition(int *array, int left, int right)
{
    int pivot = array[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[right]);
    return i + 1;
}

void QuickSort(int *array, int left, int right)
{
    if (left < right)
    {
        int pivot = Partition(array, left, right);
        QuickSort(array, left, pivot - 1);
        QuickSort(array, pivot + 1, right);
    }
}

void Heapify(int *array, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < size && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        Heapify(array, size, largest);
    }
}

void HeapSort(int *array, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(array, size, i);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        swap(&array[0], &array[i]);
        Heapify(array, i, 0);
    }
}

void ShellSort(int *array, int size)
{
    int i, j, temp;
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;
            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }
    }
}

void CountingSort(int *array, int size)
{
    int i, j, max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    int count[max + 1];
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        count[array[i]]++;
    }
    i = 0;
    j = 0;
    while (j < max + 1)
    {
        if (count[j] > 0)
        {
            array[i++] = j;
            count[j]--;
        }
        else
        {
            j++;
        }
    }
}

void RadixSort(int *array, int size)
{
    int i, j, max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        int output[size];
        int count[10] = {0};
        for (i = 0; i < size; i++)
        {
            count[(array[i] / exp) % 10]++;
        }
        for (i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        for (i = size - 1; i >= 0; i--)
        {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }
        for (i = 0; i < size; i++)
        {
            array[i] = output[i];
        }
    }
}

void BucketSort(int *array, int size)
{
    int i, j, max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    int bucket[max + 1];
    for (i = 0; i < max + 1; i++)
    {
        bucket[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        bucket[array[i]]++;
    }
    i = 0;
    j = 0;
    while (j < max + 1)
    {
        if (bucket[j] > 0)
        {
            array[i++] = j;
            bucket[j]--;
        }
        else
        {
            j++;
        }
    }
}