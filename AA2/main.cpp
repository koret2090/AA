#include <iostream>
#include "matrix.h"
#include "multiplications.h"
#include "test.h"

using namespace std;
void menu();

int main()
{
    /*
    cout << "Hello World!" << endl;

    int n = 3;
    int m = 2;

    int** matrix = create_matrix(n, m);
    int** matrix2 = create_matrix(m, n);
    //fill_matrix_with_random_nums(matrix, n, m);
    input_matrix(matrix, n, m);
    input_matrix(matrix2, m, n);

    std_matrix_mult(matrix, n, m, matrix2, m, n);
    //print_matrix(matrix, n, m);
    vinograd_matrix_mult(matrix, n, m, matrix2, m, n);
    vinograd_modified_matrix_mult(matrix, n, m, matrix2, m, n);


    delete_matrix(matrix, n);
    delete_matrix(matrix2, m);


    test();
    */

    menu();

    return 0;
}

void menu()
{
    int rows = 0;
    int columns = 0;

    int choice = -1;
    int check = 0;

    int** matrix = nullptr;
    int** matrix2 = nullptr;

    while (choice)
    {
        cout << "0 - Exit\n\
1 - Input matrixes\n\
2 - Standart\n\
3 - Vinograd\n\
4 - Vinograd modified\n\
5 - Timing tests\n\
Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Input rows amount: ";
            cin >> rows;
            cout << "\nInput columns amount: ";
            cin >> columns;
            matrix = create_matrix(rows, columns);
            input_matrix(matrix, rows, columns);

            matrix2 = create_matrix(columns, rows);
            input_matrix(matrix2, columns, rows);

            check = 1;
            break;
        case 2:
            std_matrix_mult(matrix, rows, columns, matrix2, columns, rows);
            break;
        case 3:
            vinograd_matrix_mult(matrix, rows, columns, matrix2, columns, rows);
            break;
        case 4:
            vinograd_modified_matrix_mult(matrix, rows, columns, matrix2, columns, rows);
        default:
            continue;
        }
    }

    //test();
}
