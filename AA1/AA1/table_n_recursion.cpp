#include "table_n_recursion.h"
#include <iostream>

size_t levenshtein_table_n_recursion(int** matrix, const char* str1,
    size_t len1, const char* str2, size_t len2)
{
    if (len1 == 0 || len2 == 0)
        return abs((int)(len2 - len1));

    if (matrix[len1][len2] == INFINIT)
    {
        int sub_cost = 0;
        if (str1[len1 - 1] != str2[len2 - 1])
            sub_cost = 1;

        size_t deletion = levenshtein_table_n_recursion(matrix, str1, len1 - 1, str2, len2) + DELETION_COST;
        size_t insertion = levenshtein_table_n_recursion(matrix, str1, len1, str2, len2 - 1) + INSERTION_COST;
        size_t replacement = levenshtein_table_n_recursion(matrix, str1, len1 - 1, str2, len2 - 1) + sub_cost;

        matrix[len1][len2] = my_min(deletion, insertion, replacement);
    }

    return matrix[len1][len2];
}

size_t levenshtein_table_n_recursion(const char* str1, const char* str2)
{
    size_t len1 = strlen(str1) + 1;
    size_t len2 = strlen(str2) + 1;

    // создание матрицы 
    int** matrix = (int**)create_matrix(len1, len2);

    // заполнение матрицы бесконечно большими числами
    fill_matrix_with_infinity(matrix, len1, len2);

    // заполнение 1-го столбца и 1-й строки числами по возрастанию
    matrix[0][0] = 0;
    for (size_t i = 1; i < len1; i++)
        matrix[i][0] = i;

    for (size_t j = 1; j < len2; j++)
        matrix[0][j] = j;

    len1--; len2--;
   
    int sub_cost = 0;
    if (str1[len1 - 1] != str2[len2 - 1])
        sub_cost = 1;

    size_t deletion = levenshtein_table_n_recursion(matrix, str1, len1 - 1, str2, len2) + DELETION_COST;
    size_t insertion = levenshtein_table_n_recursion(matrix, str1, len1, str2, len2 - 1) + INSERTION_COST;
    size_t replacement = levenshtein_table_n_recursion(matrix, str1, len1 - 1, str2, len2 - 1) + sub_cost;

   
    //int answer = matrix[len1 - 1][len2 - 1];
    int answer = my_min(deletion, insertion, replacement);

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++)
            std::cout << matrix[i][j] << "  ";
        std::cout << '\n';
    }


    // очищение памяти из под матрицы
    free_matrix(&matrix, len1);

    return  answer;
}
