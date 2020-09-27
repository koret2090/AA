#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdlib.h>
#include <iostream>

int** create_matrix(long int rows, long int columns);
void free_matrix(int*** matrix, long int rows);
void print_matrix(int** matrix, long int rows, long int columns);

#endif // !MATRIX_H_

