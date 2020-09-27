#include "matrix.h"

int** create_matrix(size_t rows, size_t columns)
{
    int** matrix;
    matrix = (int**)malloc(sizeof(int*) * rows);
    for (size_t i = 0; i < rows; i++)
        matrix[i] = (int*)calloc(columns, sizeof(int));

    return matrix;
}

void free_matrix(int*** matrix, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
        free((*matrix)[i]);
    free((*matrix));
}