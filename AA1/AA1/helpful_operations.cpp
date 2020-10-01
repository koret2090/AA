#include "helpful_operations.h"
#include <random>

#define RANDOM_SYMBOLS_LEN 36

void fill_matrix_with_infinity(int** matrix, long int rows, long int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            matrix[i][j] = INFINIT;
    }
}

void fill_string_with_random_symbols(long int len, char* string)
{
    const char symbols[]  = "1234567890qwertyuiopasdfghjklzxcvbnm";
    for (long int i = 0; i < len; i++)
        string[i] = symbols[rand() % RANDOM_SYMBOLS_LEN];
}
