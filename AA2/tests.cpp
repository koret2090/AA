#include "matrix.h"
#include "multiplications.h"
#include <ctime>

void test()
{
    for (int len = 100; len <= 500; len+= 100)
    {
        std::cout << "LENGTH: " << len << '\n';
        int** matrix1 = create_matrix(len, len);
        int** matrix2 = create_matrix(len, len);
        int** result_matrix = create_matrix(len, len);

        fill_matrix_with_random_nums(matrix1, len, len);
        fill_matrix_with_random_nums(matrix2, len, len);

        clock_t start = clock();
        std_matrix_mult(matrix1, len, len, matrix2, len, len, result_matrix);
        clock_t end = clock();
        std::cout << "Standart method time: " << (float)(end - start) << std::endl;

        start = clock();
        vinograd_matrix_mult(matrix1, len, len, matrix2, len, len, result_matrix);
        end = clock();
        std::cout << "Vinograd method time: " << (float)(end - start) << std::endl;

        start = clock();
        vinograd_modified_matrix_mult(matrix1, len, len, matrix2, len, len, result_matrix);
        end = clock();
        std::cout << "Vinograd Modified method time: " << (float)(end - start) << std::endl << std::endl;

        delete_matrix(matrix1, len);
        delete_matrix(matrix2, len);
        delete_matrix(result_matrix, len);
    }
}
