#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int *read_csv_dynamic(const char *filename, int *data_size){
    // Öffnen der Datei zum Lesen
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Kann die Datei nicht öffnen: %s\n", filename);
        *data_size = 0;
        return NULL;
    }

    // Anfang mit einer Kapazität von 0
    int capacity = 0;

    // Zwischenspeicher für die gelesene Zeile
    char line[MAX_LINE_LENGTH];

    // Lesen der Datei Zeile für Zeile
    int *data = NULL;
    *data_size = 0;
    char ch;
    int i = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        line[i] = ch;
        i++;
        if (ch == '\n')
        {
            line[i - 1] = '\0';
            // Aufteilen der Zeile in Spalten mit "," als Trennzeichen
            char *value = strtok(line, ",");
            while (value != NULL)
            {
                // Konvertieren des Strings in einen int-Wert
                int number = atoi(value);

                // Überprüfen, ob das Array voll ist
                if (*data_size == capacity)
                {
                    // Erhöhen der Kapazität des Arrays
                    capacity = capacity == 0 ? 1 : capacity * 2;
                    data = (int *)realloc(data, capacity * sizeof(int));
                }

                // Hinzufügen des Werts zum Array
                data[*data_size] = number;
                (*data_size)++;

                // Lesen der nächsten Spalte
                value = strtok(NULL, ",");
            }
            i = 0;
        }
    }

    // Schließen der Datei
    fclose(file);
    return data;
}


void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

void print_array_with_index(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d: %d ", i, array[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}