#include "matrix.h"

int** create_matrix(long int rows, long int columns)
{
    int** matrix;
    matrix = (int**)malloc(sizeof(int*) * rows);
    for (long int i = 0; i < rows; i++)
        matrix[i] = (int*)calloc(columns, sizeof(int));

    return matrix;
}

void free_matrix(int*** matrix, long int rows)
{
    for (long int i = 0; i < rows; i++)
        free((*matrix)[i]);
    free((*matrix));
}

void print_matrix(int** matrix, long int rows, long int columns)
{
    for (long int i = 0; i < rows; i++) {
        for (long int j = 0; j < columns; j++)
            std::cout << matrix[i][j] << "  ";
        std::cout << '\n';
    }
    std::cout << '\n';
}