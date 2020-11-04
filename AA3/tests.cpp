#include "tests.h"

void test()
{
    int* array = nullptr;
    int* copy_arr = nullptr;

    for (int len = 0; len <= 500; len+= 100)
    {
        copy_arr = create_array(len);
        array = create_array(len);
        fill_array_with_random_nums(array, len);

        copy_array(array, len, copy_arr);
        clock_t start = clock();
        bubble_sort(copy_arr, len);
        clock_t end = clock();
        std::cout << "Bubble sort time: " << (float)(end - start) << std::endl;

        copy_array(array, len, copy_arr);
        start = clock();
        insertion_sort(copy_arr, len);
        end = clock();
        std::cout << "Insertion sort time: " << (float)(end - start) << std::endl;

        copy_array(array, len, copy_arr);
        start = clock();
        choices_sort(copy_arr, len);
        end = clock();
        std::cout << "Choices sort time: " << (float)(end - start) << std::endl << std::endl;

        delete_array(array);
        delete_array(copy_arr);
    }
}
