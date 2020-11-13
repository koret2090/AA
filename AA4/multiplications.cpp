#include "matrix.h"
#include "multiplications.h"

//using namespace std;

void std_matrix_mult(int** matrix1, int row1, int col1,\
                     int** matrix2, int row2, int col2)
{
    if ((col1 != row2) || row1 == 0 || row2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    int** temp_matrix = create_matrix(row1, col2);

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            temp_matrix[i][j] = 0;
            for (int k = 0; k < col1; k++)
                temp_matrix[i][j] = temp_matrix[i][j] + matrix1[i][k] * matrix2[k][j];
        }
    }

    print_matrix(temp_matrix, row1, col2);
    delete_matrix(temp_matrix, col2);
}

void vinograd_matrix_mult(int** matrix1, int row1, int col1,\
                          int** matrix2, int row2, int col2)
{
    if ((col1 != row2) || row1 == 0 || row2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    int** temp_matrix = create_matrix(row1, col2);

    int row_factor[row1];
    for (int i = 0; i < row1; i++)
    {
        row_factor[i] = 0;
        for (int k = 0; k < col1 / 2; k++)
            row_factor[i] = row_factor[i] + matrix1[i][2 * k] * matrix1[i][2 * k + 1];
    }

    int col_factor[col2];
    for (int i = 0; i < col2; i++)
    {
        col_factor[i] = 0;
        for (int k = 0; k < row2 / 2; k++)
            col_factor[i] = col_factor[i] + matrix2[2 * k][i] * matrix2[2 * k + 1][i];
    }

    for (int i = 0; i < row1; i++)
    {
       for (int j = 0; j < col2; j++)
       {
           temp_matrix[i][j] = -row_factor[i] - col_factor[j];
           for (int k = 0; k < col1 / 2; k++)
               temp_matrix[i][j] = temp_matrix[i][j] + (matrix1[i][2 * k + 1] + matrix2[2 * k][j])
                       * (matrix1[i][2 * k] + matrix2[2 * k + 1][j]);
       }
    }

    if (col1 % 2 == 1)
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
                temp_matrix[i][j] = temp_matrix[i][j] + matrix1[i][col1 - 1] * matrix2[col1 - 1][j];
        }
    }

    print_matrix(temp_matrix, row1, col2);
    delete_matrix(temp_matrix, col2);
}

void vinograd_modified_matrix_mult(int** matrix1, int row1, int col1,\
                          int** matrix2, int row2, int col2)
{
    if ((col1 != row2) || row1 == 0 || row2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    int** temp_matrix = create_matrix(row1, col2);

    int row_factor[row1];
    int even_col1 = col1 - col1 % 2;
    for (int i = 0; i < row1; i++)
    {
        row_factor[i] = 0;
        for (int k = 0; k < even_col1; k += 2)
            row_factor[i] -= matrix1[i][k] * matrix1[i][k + 1];
    }

    int col_factor[col2];
    int even_row2 = row2 - row2 % 2;
    for (int i = 0; i < col2; i++)
    {
        col_factor[i] = 0;
        for (int k = 0; k < even_row2; k += 2)
            col_factor[i] -= matrix2[k][i] * matrix2[k + 1][i];
    }

    for (int i = 0; i < row1; i++)
    {
       for (int j = 0; j < col2; j++)
       {
           int buf = row_factor[i] + col_factor[j];
           for (int k = 0; k < even_col1; k += 2)
               buf += (matrix1[i][k + 1] + matrix2[k][j])
                       * (matrix1[i][k] + matrix2[k + 1][j]);

           temp_matrix[i][j] = buf;
       }
    }

    if (col1 % 2 == 1)
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
                temp_matrix[i][j] += matrix1[i][col1 - 1] * matrix2[col1 - 1][j];
        }
    }

    print_matrix(temp_matrix, row1, col2);
    delete_matrix(temp_matrix, col2);
}


void thread_row_mult(int** matrix1, int columns, int* row_factor, int start_row, int end_row)
{
    for (int i = start_row; i < end_row; i++)
    {
        for (int j = 0; j < columns / 2; j++)
            row_factor[i] += matrix1[i][2 * j] * matrix1[i][2 * j + 1];
    }
}

void thread_columns_mult(int** matrix2, int rows, int* col_factor,\
                         int start_column, int end_column)
{
    for (int i = start_column; i < end_column; i++)
        {
            for (int j = 0; j < rows / 2; j++)
                col_factor[i] += matrix2[2 * j][i] * matrix2[2 * j + 1][i];
        }
}

void vinograd_matrix_mult_parallel(int** matrix1, int row1, int col1,\
                          int** matrix2, int row2, int col2, int threads_amount)
{
    if ((col1 != row2) || row1 == 0 || row2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    int** temp_matrix = create_matrix(row1, col2);

    int* row_factor = (int*)calloc(row1, sizeof(int));
    std::thread* threads = new std::thread[threads_amount];

    int rows_for_thread = row1 / threads_amount;
    int start_row = 0;
    for (int i = 0; i < threads_amount; i++)
    {
        int end_row = start_row + rows_for_thread;
        if (i == threads_amount - 1)
            end_row = row1;

        threads[i] = std::thread(thread_row_mult, matrix1, col1, row_factor, start_row, end_row);
        start_row = end_row;
    }

    for (int i = 0; i < threads_amount; i++)
        threads[i].join();

    int* col_factor = (int*)calloc(col2, sizeof(int));

    int columns_for_thread = col2 / threads_amount;
    int start_column = 0;
    for (int i = 0; i < threads_amount; i++)
    {
        int end_column = start_column + columns_for_thread;
        if (i == threads_amount - 1)
            end_column = col2;

        threads[i] = std::thread(thread_columns_mult, matrix2, col2, col_factor,\
                            start_column, end_column);
        start_column = end_column;
    }

    for (int i = 0; i < threads_amount; i++)
        threads[i].join();

    for (int i = 0; i < row1; i++)
    {
       for (int j = 0; j < col2; j++)
       {
           temp_matrix[i][j] = -row_factor[i] - col_factor[j];
           for (int k = 0; k < col1 / 2; k++)
               temp_matrix[i][j] = temp_matrix[i][j] + (matrix1[i][2 * k + 1] + matrix2[2 * k][j])
                       * (matrix1[i][2 * k] + matrix2[2 * k + 1][j]);
       }
    }

    if (col1 % 2 == 1)
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
                temp_matrix[i][j] = temp_matrix[i][j] + matrix1[i][col1 - 1] * matrix2[col1 - 1][j];
        }
    }

    print_matrix(temp_matrix, row1, col2);
    free(row_factor);
    free(col_factor);
    delete_matrix(temp_matrix, col2);

}


void thread_cycle(int** matrix1, int row1, int col1, int** matrix2, int row2, int col2,\
    int** temp_matrix, int* row_factor, int* col_factor, int start_row, int end_row)
{
    for (int i = start_row; i < end_row; i++)
    {
       for (int j = 0; j < col2; j++)
       {
           temp_matrix[i][j] = -row_factor[i] - col_factor[j];
           for (int k = 0; k < col1 / 2; k++)
               temp_matrix[i][j] = temp_matrix[i][j] + (matrix1[i][2 * k + 1] + matrix2[2 * k][j])
                       * (matrix1[i][2 * k] + matrix2[2 * k + 1][j]);
       }
    }
}
void vinograd_matrix_mult_parallel2(int** matrix1, int row1, int col1,\
                          int** matrix2, int row2, int col2, int threads_amount)
{
    if ((col1 != row2) || row1 == 0 || row2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    int** temp_matrix = create_matrix(row1, col2);

    int* row_factor = (int*)calloc(row1, sizeof(int));
    for (int i = 0; i < row1; i++)
    {
        row_factor[i] = 0;
        for (int k = 0; k < col1 / 2; k++)
            row_factor[i] = row_factor[i] + matrix1[i][2 * k] * matrix1[i][2 * k + 1];
    }

    int* col_factor = (int*)calloc(col2, sizeof(int));
    for (int i = 0; i < col2; i++)
    {
        col_factor[i] = 0;
        for (int k = 0; k < row2 / 2; k++)
            col_factor[i] = col_factor[i] + matrix2[2 * k][i] * matrix2[2 * k + 1][i];
    }


    std::thread* threads = new std::thread[threads_amount];

    int rows_for_thread = row1 / threads_amount;
    int start_row = 0;
    for (int i = 0; i < threads_amount; i++)
    {
        int end_row = start_row + rows_for_thread;
        if (i == threads_amount - 1)
            end_row = row1;

        threads[i] = std::thread(thread_cycle, matrix1, row1, col1, matrix2, row2, col2,\
                     temp_matrix, row_factor, col_factor, start_row, end_row);
        start_row = end_row;
    }

    for (int i = 0; i < threads_amount; i++)
        threads[i].join();

    if (col1 % 2 == 1)
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
                temp_matrix[i][j] = temp_matrix[i][j] + matrix1[i][col1 - 1] * matrix2[col1 - 1][j];
        }
    }

    print_matrix(temp_matrix, row1, col2);
    free(row_factor);
    free(col_factor);
    delete_matrix(temp_matrix, col2);
}

void std_matrix_mult(int** matrix1, int row1, int col1,\
                     int** matrix2, int row2, int col2, int** result_matrix)
{
    if ((col1 != row2) || row1 == 0 || row2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result_matrix[i][j] = 0;
            for (int k = 0; k < col1; k++)
                result_matrix[i][j] = result_matrix[i][j] + matrix1[i][k] * matrix2[k][j];
        }
    }
}

void vinograd_matrix_mult(int** matrix1, int row1, int col1,\
                          int** matrix2, int row2, int col2, int** result_matrix)
{
    if ((col1 != row2) || row1 == 0 || row2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    int row_factor[row1];
    for (int i = 0; i < row1; i++)
    {
        row_factor[i] = 0;
        for (int k = 0; k < col1 / 2; k++)
            row_factor[i] = row_factor[i] + matrix1[i][2 * k] * matrix1[i][2 * k + 1];
    }

    int col_factor[col2];
    for (int i = 0; i < col2; i++)
    {
        col_factor[i] = 0;
        for (int k = 0; k < row2 / 2; k++)
            col_factor[i] = col_factor[i] + matrix2[2 * k][i] * matrix2[2 * k + 1][i];
    }

    for (int i = 0; i < row1; i++)
    {
       for (int j = 0; j < col2; j++)
       {
           result_matrix[i][j] = -row_factor[i] - col_factor[j];
           for (int k = 0; k < col1 / 2; k++)
               result_matrix[i][j] = result_matrix[i][j] + (matrix1[i][2 * k + 1] + matrix2[2 * k][j])
                       * (matrix1[i][2 * k] + matrix2[2 * k + 1][j]);
       }
    }

    if (col1 % 2 == 1)
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
                result_matrix[i][j] = result_matrix[i][j] + matrix1[i][col1 - 1] * matrix2[col1 - 1][j];
        }
    }
}

void vinograd_modified_matrix_mult(int** matrix1, int row1, int col1,\
                          int** matrix2, int row2, int col2, int** result_matrix)
{
    if ((col1 != row2) || row1 == 0 || row2 == 0)
    {
        std::cout << "Incorrect matrixes" << std::endl;
        return;
    }

    int row_factor[row1];
    int even_col1 = col1 - col1 % 2;
    for (int i = 0; i < row1; i++)
    {
        row_factor[i] = 0;
        for (int k = 0; k < even_col1; k += 2)
            row_factor[i] -= matrix1[i][k] * matrix1[i][k + 1];
    }

    int col_factor[col2];
    int even_row2 = row2 - row2 % 2;
    for (int i = 0; i < col2; i++)
    {
        col_factor[i] = 0;
        for (int k = 0; k < even_row2; k += 2)
            col_factor[i] -= matrix2[k][i] * matrix2[k + 1][i];
    }

    for (int i = 0; i < row1; i++)
    {
       for (int j = 0; j < col2; j++)
       {
           int buf = row_factor[i] + col_factor[j];
           for (int k = 0; k < even_col1; k += 2)
               buf += (matrix1[i][k + 1] + matrix2[k][j])
                       * (matrix1[i][k] + matrix2[k + 1][j]);

           result_matrix[i][j] = buf;
       }
    }

    if (col1 % 2 == 1)
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
                result_matrix[i][j] += matrix1[i][col1 - 1] * matrix2[col1 - 1][j];
        }
    }
}
