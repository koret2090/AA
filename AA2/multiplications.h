#ifndef MULTIPLICATIONS_H
#define MULTIPLICATIONS_H

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

#endif // MULTIPLICATIONS_H
