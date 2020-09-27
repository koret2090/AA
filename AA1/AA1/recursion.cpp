#include "recursion.h"

size_t levenshtein_distance_recursion(const char* str1, size_t len1, const char* str2, size_t len2)
{
    // если одно слово по итогу короче другого, то
    // оставшаяся длина - кол-во вставок недостающих символов
    if (len1 == 0)
        return len2;

    if (len2 == 0)
        return len1;

    int sub_cost = 0;
    if (str1[len1 - 1] != str2[len2 - 1])
        sub_cost = 1;

    size_t deletion = levenshtein_distance_recursion(str1, len1 - 1, str2, len2) + DELETION_COST;
    size_t insertion = levenshtein_distance_recursion(str1, len1, str2, len2 - 1) + INSERTION_COST;
    size_t sub = levenshtein_distance_recursion(str1, len1 - 1, str2, len2 - 1) + sub_cost;

    return my_min(deletion, insertion, sub);
}


size_t levenshtein_distance_recursion(const char* str1, const char* str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    // если одно слово по итогу короче другого, то
    // оставшаяся длина - кол-во вставок недостающих символов
    if (len1 == 0)
        return len2;

    if (len2 == 0)
        return len1;

    int sub_cost = 0;
    if (str1[len1 - 1] != str2[len2 - 1])
        sub_cost = 1;

    size_t deletion = levenshtein_distance_recursion(str1, len1 - 1, str2, len2) + DELETION_COST;
    size_t insertion = levenshtein_distance_recursion(str1, len1, str2, len2 - 1) + INSERTION_COST;
    size_t sub = levenshtein_distance_recursion(str1, len1 - 1, str2, len2 - 1) + sub_cost;

    return my_min(deletion, insertion, sub);
}