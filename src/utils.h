#ifndef UTILS_H
#define UTILS_H

int *read_csv_dynamic(const char *filename, int *data_size);
void print_array(int *array, int size);
void print_array_with_index(int *array, int size);
void swap(int *a, int *b);
#endif
