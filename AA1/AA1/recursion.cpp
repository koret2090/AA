#include "recursion.h"

long int levenshtein_recursion(const char* str1, long int len1, const char* str2, long int len2)
{
    // если одно слово по итогу короче другого, то
    // оставшаяся длина - кол-во вставок недостающих символов
    if (len1 <= 0 || len2 <= 0)
        return abs((int)(len2 - len1));

    int sub_cost = 0;
    if (str1[len1 - 1] != str2[len2 - 1])
        sub_cost = 1;

    long int deletion = levenshtein_recursion(str1, len1 - 1, str2, len2) + DELETION_COST;
    long int insertion = levenshtein_recursion(str1, len1, str2, len2 - 1) + INSERTION_COST;
    long int replacement = levenshtein_recursion(str1, len1 - 1, str2, len2 - 1) + sub_cost;

    return my_min(deletion, insertion, replacement);
}


long int levenshtein_recursion(const char* str1, const char* str2)
{
    long int len1 = strlen(str1);
    long int len2 = strlen(str2);

    // если одно слово по итогу короче другого, то
    // оставшаяся длина - кол-во вставок недостающих символов
    if (len1 <= 0 || len2 <= 0)
        return abs((int)(len2 - len1));

    int sub_cost = 0;
    if (str1[len1 - 1] != str2[len2 - 1])
        sub_cost = 1;

    long int deletion = levenshtein_recursion(str1, len1 - 1, str2, len2) + DELETION_COST;
    long int insertion = levenshtein_recursion(str1, len1, str2, len2 - 1) + INSERTION_COST;
    long int replacement = levenshtein_recursion(str1, len1 - 1, str2, len2 - 1) + sub_cost;

    return my_min(deletion, insertion, replacement);
}