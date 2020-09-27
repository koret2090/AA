#include "table_n_recursion.h"
#include <iostream>

long int levenshtein_table_n_recursion(int** matrix, const char* str1,
    long int len1, const char* str2, long int len2)
{
    if (len1 <= 0 || len2 <= 0)
        return abs((int)(len2 - len1));

    if (matrix[len1][len2] == INFINIT)
    {
        int sub_cost = 0;
        if (str1[len1 - 1] != str2[len2 - 1])
            sub_cost = 1;

        long int deletion = levenshtein_table_n_recursion(matrix, str1, len1 - 1, str2, len2) + DELETION_COST;
        long int insertion = levenshtein_table_n_recursion(matrix, str1, len1, str2, len2 - 1) + INSERTION_COST;
        long int replacement = levenshtein_table_n_recursion(matrix, str1, len1 - 1, str2, len2 - 1) + sub_cost;

        matrix[len1][len2] = my_min(deletion, insertion, replacement);
    }

    return matrix[len1][len2];
}

long int levenshtein_table_n_recursion(const char* str1, const char* str2)
{
    long int len1 = strlen(str1) + 1;
    long int len2 = strlen(str2) + 1;

    // создание матрицы 
    int** matrix = (int**)create_matrix(len1, len2);

    // заполнение матрицы бесконечно большими числами
    fill_matrix_with_infinity(matrix, len1, len2);

    // заполнение 1-го столбца и 1-й строки числами по возрастанию
    matrix[0][0] = 0;
    for (long int i = 1; i < len1; i++)
        matrix[i][0] = i;

    for (long int j = 1; j < len2; j++)
        matrix[0][j] = j;

    len1--; len2--;
   
    int sub_cost = 0;
    if (str1[len1 - 1] != str2[len2 - 1])
        sub_cost = 1;

    long int deletion = levenshtein_table_n_recursion(matrix, str1, len1 - 1, str2, len2) + DELETION_COST;
    long int insertion = levenshtein_table_n_recursion(matrix, str1, len1, str2, len2 - 1) + INSERTION_COST;
    long int replacement = levenshtein_table_n_recursion(matrix, str1, len1 - 1, str2, len2 - 1) + sub_cost;

   
    //int answer = matrix[len1 - 1][len2 - 1];
    int answer = my_min(deletion, insertion, replacement);

    print_matrix(matrix, len1, len2);


    // очищение памяти из под матрицы
    free_matrix(&matrix, len1);

    return  answer;
}
