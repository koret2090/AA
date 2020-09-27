#include "damerau.h"

size_t damerau_levenshtein_distance(const char* str1, const char* str2)
{
    size_t len1 = strlen(str1) + 1;
    size_t len2 = strlen(str2) + 1;

    //int** matrix = new int* [(len1 + 1) * (len2 + 1)];
    // создание матрицы 
    int** matrix = (int**)create_matrix(len1, len2);

    // заполнение 1-го столбца и 1-й строки числами по возрастанию
    matrix[0][0] = 0;
    for (size_t i = 1; i < len1; i++)
        matrix[i][0] = i;

    for (size_t j = 1; j < len2; j++)
        matrix[0][j] = j;

    for (size_t i = 1; i < len1; i++)
    {
        for (size_t j = 1; j < len2; j++)
        {
            int sub_cost = 0;
            if (str1[i - 1] != str2[j - 1])
                sub_cost = 1;

            matrix[i][j] = my_min(matrix[i - 1][j] + DELETION_COST,    // удаление
                matrix[i][j - 1] + INSERTION_COST,   // вставка
                matrix[i - 1][j - 1] + sub_cost);    // замена


            if (i > 1 && j > 1 && str1[i - 1] == str2[j - 2]
                && str1[i - 2] == str2[j - 1])
            {
                matrix[i][j] = std::min(matrix[i][j], matrix[i - 2][j - 2] + sub_cost); // перестановка
            }
        }
    }

    int answer = matrix[len1 - 1][len2 - 1];

    // очищение памяти из под матрицы
    free_matrix(&matrix, len1);

    return  answer;
}