#include "matrix.h"

using namespace std;

int** create_matrix(int rows, int columns)
{
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int [columns];

    return matrix;
}

void delete_matrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        delete[]matrix[i];

    delete [] matrix;
}

void fill_matrix_with_random_nums(int** matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            matrix[i][j] = rand();
    }
}

void print_matrix(int** matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }
    cout << endl;
}

void input_matrix(int** matrix, int rows, int columns)
{
    cout << "Input matrix" << endl;
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            cin >> matrix[i][j];
    }
    cout << endl;
}
