#include "table.h"

long int levenshtein_distance(const char* str1, const char* str2)
{
    long int len1 = strlen(str1) + 1;
    long int len2 = strlen(str2) + 1;

    // создание матрицы 
    int** matrix = create_matrix(len1, len2);

    // заполнение 1-го столбца и 1-й строки числами по возрастанию
    matrix[0][0] = 0;
    for (long int i = 1; i < len1; i++)
        matrix[i][0] = i;

    for (long int j = 1; j < len2; j++)
        matrix[0][j] = j;

    for (long int i = 1; i < len1; i++)
    {
        for (long int j = 1; j < len2; j++)
        {
            int sub_cost = 0;
            if (str1[i - 1] != str2[j - 1])
                sub_cost = 1;

            matrix[i][j] = my_min(matrix[i - 1][j] + DELETION_COST,    // удаление
                matrix[i][j - 1] + INSERTION_COST,   // вставка
                matrix[i - 1][j - 1] + sub_cost);    // замена
        }
    }

    int answer = matrix[len1 - 1][len2 - 1];

    print_matrix(matrix, len1, len2);
    // очищение памяти из под матрицы
    free_matrix(&matrix, len1);

    return  answer;
}


