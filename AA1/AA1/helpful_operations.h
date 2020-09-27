#ifndef HELPFUL_OPERATIONS_H_
#define HELPFUL_OPERATIONS_H_

#include <cstring>
#include <cmath>


#define DELETION_COST 1
#define INSERTION_COST 1
#define INFINIT 10000

void fill_matrix_with_infinity(int** matrix, long int rows, long int columns);
void fill_string_with_random_symbols(long int len, char* string);

template<typename T>
T my_min(T var1, T var2, T var3)
{
    if (var1 <= var2 && var1 <= var3)
        return var1;

    if (var2 <= var1 && var2 <= var3)
        return var2;

    if (var3 <= var1 && var3 <= var2)
        return var3;
}

#endif // !HELPFUL_OPERATIONS_H_

