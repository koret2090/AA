#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <clocale>

int** create_matrix(int rows, int columns);
void delete_matrix(int** matrix, int rows);
void fill_matrix_with_random_nums(int** matrix, int rows, int columns);
void print_matrix(int** matrix, int rows, int columns);
void input_matrix(int** matrix, int rows, int columns);

#endif // MATRIX_H
