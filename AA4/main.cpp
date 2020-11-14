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

    int rows2 = 0;
    int columns2 = 0;

    int choice = -1;

    int** matrix = nullptr;
    int** matrix2 = nullptr;

    while (choice)
    {
        cout << "0 - Exit\n\
1 - Input matrixes\n\
2 - Vinograd\n\
3 - Vinograd parallel 1\n\
4 - Vinograd parallel 2\n\
5 - Timing tests\n\
Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Input rows amount: ";
            cin >> rows;
            cout << "Input columns amount: ";
            cin >> columns;

            cout << "\nInput rows amount: ";
            cin >> rows2;
            cout << "Input columns amount: ";
            cin >> columns2;
            cout << endl;
            if (rows > 0 && columns > 0 && rows2 > 0 && columns2 > 0)
            {
                matrix = create_matrix(rows, columns);
                input_matrix(matrix, rows, columns);

                matrix2 = create_matrix(rows2, columns2);
                input_matrix(matrix2, rows2, columns2);
            }
            else
                cout << "\nIncorrect size!\n\n";

            break;
        case 2:
            vinograd_matrix_mult(matrix, rows, columns, matrix2, rows2, columns2);
            break;
        case 3:
            vinograd_matrix_mult_parallel(matrix, rows, columns, matrix2, rows2, columns2, 4);
            break;
        case 4:
            vinograd_matrix_mult_parallel2(matrix, rows, columns, matrix2, rows2, columns2, 4);
            break;
        case 5:
            test();
            break;
        default:
            continue;
        }
    }
}
