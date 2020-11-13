#ifndef MULTIPLICATIONS_H
#define MULTIPLICATIONS_H

#include <thread>
#include <iostream>

void std_matrix_mult(int** matrix1, int n1, int m1,\
                     int** matrix2, int n2, int m2);
void vinograd_matrix_mult(int** matrix1, int n1, int m1,\
                          int** matrix2, int n2, int m2);
void vinograd_modified_matrix_mult(int** matrix1, int n1, int m1,\
                          int** matrix2, int n2, int m2);

void std_matrix_mult(int** matrix1, int n1, int m1,\
                     int** matrix2, int n2, int m2, int** result_matrix);
void vinograd_matrix_mult(int** matrix1, int n1, int m1,\
                          int** matrix2, int n2, int m2, int** result_matrix);
void vinograd_modified_matrix_mult(int** matrix1, int n1, int m1,\
                          int** matrix2, int n2, int m2, int** result_matrix);

void thread_row_mult(int** matrix1, int columns, int* row_factor, int start_row, int end_row);
void thread_columns_mult(int** matrix2, int rows, int* col_factor,\
                         int start_column, int end_column);
void vinograd_matrix_mult_parallel(int** matrix1, int n1, int m1,\
                          int** matrix2, int n2, int m2, int threads_amount);

void thread_cycle(int** matrix1, int row1, int col1, int** matrix2, int row2, int col2,\
    int** temp_matrix, int* row_factor, int* col_factor, int start_row, int end_row);
void vinograd_matrix_mult_parallel2(int** matrix1, int row1, int col1,\
                          int** matrix2, int row2, int col2, int threads_amount);
#endif // MULTIPLICATIONS_H
