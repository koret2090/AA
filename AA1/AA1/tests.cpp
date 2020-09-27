#include "tests.h"

void test()
{
	clock_t time_start = clock();
	levenshtein_distance("mama", "mav");
	clock_t end = clock();
	std::cout << "TIME: " << (float)(end - time_start);
}