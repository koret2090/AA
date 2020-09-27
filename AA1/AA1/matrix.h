#pragma once
#include <stdlib.h>

int** create_matrix(size_t rows, size_t columns);
void free_matrix(int*** matrix, size_t rows);