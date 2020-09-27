#ifndef TABLE_N_RECURSION_H_

#define TABLE_N_RECURSION_H_

#include "helpful_operations.h"
#include "matrix.h"

size_t levenshtein_table_n_recursion(const char* str1, const char* str2);
size_t levenshtein_table_n_recursion(int** matrix, const char* str1,
    size_t len1, const char* str2, size_t len2);

#endif // !TABLE_N_RECURSION_H_

