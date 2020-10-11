#include <iostream>
#include "matrix.h"
#include "multiplications.h"
#include "test.h"

using namespace std;

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
    */

    test();

    return 0;
}
