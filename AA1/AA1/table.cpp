#include "table.h"

long int levenshtein_distance(const char* str1, const char* str2)
{
    long int len1 = strlen(str1) + 1;
    long int len2 = strlen(str2) + 1;

    // �������� ������� 
    int** matrix = create_matrix(len1, len2);

    // ���������� 1-�� ������� � 1-� ������ ������� �� �����������
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

            matrix[i][j] = my_min(matrix[i - 1][j] + DELETION_COST,    // ��������
                matrix[i][j - 1] + INSERTION_COST,   // �������
                matrix[i - 1][j - 1] + sub_cost);    // ������
        }
    }

    int answer = matrix[len1 - 1][len2 - 1];

    print_matrix(matrix, len1, len2);
    // �������� ������ �� ��� �������
    free_matrix(&matrix, len1);

    return  answer;
}


