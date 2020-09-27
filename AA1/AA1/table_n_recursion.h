#ifndef TABLE_N_RECURSION_H_

#define TABLE_N_RECURSION_H_

#include "helpful_operations.h"
#include "matrix.h"

long int levenshtein_table_n_recursion(const char* str1, const char* str2);
long int levenshtein_table_n_recursion(int** matrix, const char* str1,
    long int len1, const char* str2, long int len2);

#endif // !TABLE_N_RECURSION_H_

