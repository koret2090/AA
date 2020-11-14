#include "matrix.h"
#include "multiplications.h"
#include <ctime>

using namespace std;

void test()
{
    int threads_amount = 2;
    cout << "Insert threads' amount" << endl;
    cin >> threads_amount;

    for (int len = 100; len <= 500; len+= 100)
    {
        std::cout << "LENGTH: " << len << '\n';
        int** matrix1 = create_matrix(len, len);
        int** matrix2 = create_matrix(len, len);
        int** result_matrix = create_matrix(len, len);

        fill_matrix_with_random_nums(matrix1, len, len);
        fill_matrix_with_random_nums(matrix2, len, len);

        float sum = 0;
        for (int _ = 0; _ < 10; _++)
        {
            clock_t start = clock();
            vinograd_matrix_mult(matrix1, len, len, matrix2, len, len, result_matrix);
            clock_t end = clock();
            sum += (float)(end - start);
        }

        std::cout << "Vinograd method time: " << sum / 10 << std::endl;

        sum = 0;
        for (int _ = 0; _ < 10; _++)
        {
            clock_t start = clock();
            vinograd_matrix_mult_parallel(matrix1, len, len, matrix2, len, len, threads_amount, result_matrix);
            clock_t end = clock();
            sum += (float)(end - start);
        }

        std::cout << "Vinograd parallel 1 method time: " << sum / 20 << std::endl;

        sum = 0;
        for (int _ = 0; _ < 10; _++)
        {
            clock_t start = clock();
            vinograd_matrix_mult_parallel2(matrix1, len, len, matrix2, len, len, threads_amount, result_matrix);
            clock_t end = clock();
            sum += (float)(end - start);
        }

        std::cout << "Vinograd parallel 2 method time: " << sum / 10 << std::endl << std::endl;

        delete_matrix(matrix1, len);
        delete_matrix(matrix2, len);
        delete_matrix(result_matrix, len);
    }
}
