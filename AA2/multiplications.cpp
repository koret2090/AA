#include "multiplications.h"
#include "matrix.h"

void std_matrix_mult(int** matrix1, int n1, int m1,\
                     int** matrix2, int n2, int m2)
{
    if ((m1 != n2) || n1 == 0 || n2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    int** temp_matrix = create_matrix(n1, m2);

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            temp_matrix[i][j] = 0;
            for (int k = 0; k < m1; k++)
                temp_matrix[i][j] = temp_matrix[i][j] + matrix1[i][k] * matrix2[k][j];
        }
    }

    print_matrix(temp_matrix, n1, m2);
    delete_matrix(temp_matrix, m1);
}

void vinograd_matrix_mult(int** matrix1, int n1, int m1,\
                          int** matrix2, int n2, int m2)
{
    if ((m1 != n2) || n1 == 0 || n2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    int** temp_matrix = create_matrix(n1, m2);

    int row_factor[n1];
    for (int i = 0; i < n1; i++)
    {
        row_factor[i] = 0;
        for (int k = 0; k < m1 / 2; k++)
            row_factor[i] = row_factor[i] + matrix1[i][2 * k] * matrix1[i][2 * k + 1];
    }

    int col_factor[m2];
    for (int i = 0; i < m2; i++)
    {
        col_factor[i] = 0;
        for (int k = 0; k < n2 / 2; k++)
            col_factor[i] = col_factor[i] + matrix2[2 * k][i] * matrix2[2 * k + 1][i];
    }

    for (int i = 0; i < n1; i++)
    {
       for (int j = 0; j < m2; j++)
       {
           temp_matrix[i][j] = -row_factor[i] - col_factor[j];
           for (int k = 0; k < m1 / 2; k++)
               temp_matrix[i][j] = temp_matrix[i][j] + (matrix1[i][2 * k + 1] + matrix2[2 * k][j])
                       * (matrix1[i][2 * k] + matrix2[2 * k + 1][j]);
       }
    }

    if (m1 % 2 == 1)
    {
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
                temp_matrix[i][j] = temp_matrix[i][j] + matrix1[i][m1 - 1] * matrix2[m1 - 1][j];
        }
    }

    print_matrix(temp_matrix, n1, m2);
    delete_matrix(temp_matrix, m1);
}

void vinograd_modified_matrix_mult(int** matrix1, int n1, int m1,\
                          int** matrix2, int n2, int m2)
{
    if ((m1 != n2) || n1 == 0 || n2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    int** temp_matrix = create_matrix(n1, m2);

    int row_factor[n1];
    int even_m1 = m1 - m1 % 2;
    for (int i = 0; i < n1; i++)
    {
        row_factor[i] = 0;
        for (int k = 0; k < even_m1; k += 2)
            row_factor[i] -= matrix1[i][k] * matrix1[i][k + 1];
    }

    int col_factor[m2];
    int even_n2 = n2 - n2 % 2;
    for (int i = 0; i < m2; i++)
    {
        col_factor[i] = 0;
        for (int k = 0; k < even_n2; k += 2)
            col_factor[i] -= matrix2[k][i] * matrix2[k + 1][i];
    }

    for (int i = 0; i < n1; i++)
    {
       for (int j = 0; j < m2; j++)
       {
           int buf = row_factor[i] + col_factor[j];
           for (int k = 0; k < even_m1; k += 2)
               buf += (matrix1[i][k + 1] + matrix2[k][j])
                       * (matrix1[i][k] + matrix2[k + 1][j]);

           temp_matrix[i][j] = buf;
       }
    }

    if (m1 % 2 == 1)
    {
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
                temp_matrix[i][j] += matrix1[i][m1 - 1] * matrix2[m1 - 1][j];
        }
    }

    print_matrix(temp_matrix, n1, m2);
    delete_matrix(temp_matrix, m1);
}

void std_matrix_mult(int** matrix1, int n1, int m1,\
                     int** matrix2, int n2, int m2, int** result_matrix)
{
    if ((m1 != n2) || n1 == 0 || n2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            result_matrix[i][j] = 0;
            for (int k = 0; k < m1; k++)
                result_matrix[i][j] = result_matrix[i][j] + matrix1[i][k] * matrix2[k][j];
        }
    }
}

void vinograd_matrix_mult(int** matrix1, int n1, int m1,\
                          int** matrix2, int n2, int m2, int** result_matrix)
{
    if ((m1 != n2) || n1 == 0 || n2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    int row_factor[n1];
    for (int i = 0; i < n1; i++)
    {
        row_factor[i] = 0;
        for (int k = 0; k < m1 / 2; k++)
            row_factor[i] = row_factor[i] + matrix1[i][2 * k] * matrix1[i][2 * k + 1];
    }

    int col_factor[m2];
    for (int i = 0; i < m2; i++)
    {
        col_factor[i] = 0;
        for (int k = 0; k < n2 / 2; k++)
            col_factor[i] = col_factor[i] + matrix2[2 * k][i] * matrix2[2 * k + 1][i];
    }

    for (int i = 0; i < n1; i++)
    {
       for (int j = 0; j < m2; j++)
       {
           result_matrix[i][j] = -row_factor[i] - col_factor[j];
           for (int k = 0; k < m1 / 2; k++)
               result_matrix[i][j] = result_matrix[i][j] + (matrix1[i][2 * k + 1] + matrix2[2 * k][j])
                       * (matrix1[i][2 * k] + matrix2[2 * k + 1][j]);
       }
    }

    if (m1 % 2 == 1)
    {
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
                result_matrix[i][j] = result_matrix[i][j] + matrix1[i][m1 - 1] * matrix2[m1 - 1][j];
        }
    }
}

void vinograd_modified_matrix_mult(int** matrix1, int n1, int m1,\
                          int** matrix2, int n2, int m2, int** result_matrix)
{
    if ((m1 != n2) || n1 == 0 || n2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    int row_factor[n1];
    int even_m1 = m1 - m1 % 2;
    for (int i = 0; i < n1; i++)
    {
        row_factor[i] = 0;
        for (int k = 0; k < even_m1; k += 2)
            row_factor[i] -= matrix1[i][k] * matrix1[i][k + 1];
    }

    int col_factor[m2];
    int even_n2 = n2 - n2 % 2;
    for (int i = 0; i < m2; i++)
    {
        col_factor[i] = 0;
        for (int k = 0; k < even_n2; k += 2)
            col_factor[i] -= matrix2[k][i] * matrix2[k + 1][i];
    }

    for (int i = 0; i < n1; i++)
    {
       for (int j = 0; j < m2; j++)
       {
           int buf = row_factor[i] + col_factor[j];
           for (int k = 0; k < even_m1; k += 2)
               buf += (matrix1[i][k + 1] + matrix2[k][j])
                       * (matrix1[i][k] + matrix2[k + 1][j]);

           result_matrix[i][j] = buf;
       }
    }

    if (m1 % 2 == 1)
    {
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
                result_matrix[i][j] += matrix1[i][m1 - 1] * matrix2[m1 - 1][j];
        }
    }
}
