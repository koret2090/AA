#include "tests.h"

void test()
{
    char str1[512] = "";
    char str2[512] = "";

    fill_string_with_random_symbols(500, str1);
    fill_string_with_random_symbols(500, str2);

    //std::cout << "STR1: " << str1 << std::endl;
    //std::cout << "STR2: " << str2 << std::endl;

    clock_t time_start = clock();
    levenshtein_table_n_recursion(str1, str2);
	clock_t end = clock();
	std::cout << "TIME: " << (float)(end - time_start);
}
