#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int main()
{
    int data_size;
    int expression;
    int *data = read_csv_dynamic("../ressources/exampleNumbers.csv", &data_size);
    printf("gibt eine Zahl von 1 bis 9 ein: ");
    scanf("%d", &expression);

    clock_t start_time;
    clock_t end_time;
    double elapsed_time;

    switch (expression)
    {
    case 1:
        printf("BubbleSort\n");
        start_time = clock();
        BubbleSort(data, data_size);
        end_time = clock();
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Elapsed time: %f seconds\n", elapsed_time);
        break;
    case 2:
        printf("InsertionSort\n");
        start_time = clock();
        InsertionSort(data, data_size);
        end_time = clock();
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Elapsed time: %f seconds\n", elapsed_time);
        break;
    case 3:
        printf("SelectionSort\n");
        start_time = clock();
        SelectionSort(data, data_size);
        end_time = clock();
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Elapsed time: %f seconds\n", elapsed_time);
        break;
    case 4:
        printf("MergeSort\n");
        start_time = clock();
        MergeSort(data, data_size);
        end_time = clock();
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Elapsed time: %f seconds\n", elapsed_time);
        break;
    case 5:
        printf("QuickSort\n");
        start_time = clock();
        QuickSort(data, data_size);
        end_time = clock();
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Elapsed time: %f seconds\n", elapsed_time);
        break;
    case 6:
        printf("HeapSort\n");
        start_time = clock();
        HeapSort(data, data_size);
        end_time = clock();
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Elapsed time: %f seconds\n", elapsed_time);
        break;
    case 7:
        printf("CountingSort\n");
        start_time = clock();
        CountingSort(data, data_size);
        end_time = clock();
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Elapsed time: %f seconds\n", elapsed_time);
        break;
    case 8:
        printf("RadixSort\n");
        start_time = clock();
        RadixSort(data, data_size);
        end_time = clock();
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Elapsed time: %f seconds\n", elapsed_time);
        break;
    case 9:
        printf("BucketSort\n");
        start_time = clock();
        BucketSort(data, data_size);
        end_time = clock();
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Elapsed time: %f seconds\n", elapsed_time);
        break;
    default:
        printf("Fehler");
        break;
    }

    free(data);
    return 0;
}