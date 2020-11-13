#include <iostream>
#include "matrix.h"
#include "multiplications.h"
#include "test.h"

using namespace std;
void menu();

int main()
{

    menu();




    return 0;
}

void menu()
{
    int rows = 0;
    int columns = 0;

    int choice = -1;

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
            if (rows > 0 && columns > 0)
            {
                matrix = create_matrix(rows, columns);
                input_matrix(matrix, rows, columns);

                matrix2 = create_matrix(columns, rows);
                input_matrix(matrix2, columns, rows);
            }
            else
                cout << "\nIncorrect size!\n\n";

            break;
        case 2:
            std_matrix_mult(matrix, rows, columns, matrix2, columns, rows);
            break;
        case 3:
            vinograd_matrix_mult(matrix, rows, columns, matrix2, columns, rows);
            break;
        case 4:
            //vinograd_modified_matrix_mult(matrix, rows, columns, matrix2, columns, rows);
            //vinograd_matrix_mult_parallel(matrix, rows, columns, matrix2, columns, rows, 4);
            vinograd_matrix_mult_parallel2(matrix, rows, columns, matrix2, columns, rows, 4);
            break;
        case 5:
            test();
            break;
        default:
            continue;
        }
    }
}
