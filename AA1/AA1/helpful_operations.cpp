#include "helpful_operations.h"
#include <random>

#define RANDOM_SYMBOLS_LEN 37

void fill_matrix_with_infinity(int** matrix, size_t rows, size_t columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            matrix[i][j] = INFINIT;
    }
}

void fill_string_with_random_symbols(size_t len, char* string)
{
    const char symbols[]  = "1234567890qwertyuiopasdfghjklzxcvbnm";
    for (size_t i = 0; i < len; i++)
        string[i] = symbols[rand() % RANDOM_SYMBOLS_LEN];
}