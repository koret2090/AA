#include "tests.h"

void test()
{
    int* array = nullptr;
    int* copy_arr = nullptr;

    for (int len = 100; len <= 500; len+= 100)
    {
        std::cout << "LEN " << len << std::endl;
        copy_arr = create_array(len);
        array = create_array(len);
        fill_array_with_random_nums(array, len);
        //reverse_bubble_sort(array, len);

        float sum = 0;
        copy_array(array, len, copy_arr);
        for (int _ = 0; _ < 10; _++)
        {
            copy_array(array, len, copy_arr);
            clock_t start = clock();
            bubble_sort(copy_arr, len);
            clock_t end = clock();
            sum += (float)(end - start);
        }
        std::cout << "Bubble sort time: " << sum / 10 << std::endl;

        sum = 0;
        copy_array(array, len, copy_arr);
        for (int _ = 0; _ < 10; _++)
        {
            copy_array(array, len, copy_arr);
            clock_t start = clock();
            insertion_sort(copy_arr, len);
            clock_t end = clock();
            sum += (float)(end - start);
        }
        std::cout << "Insertion sort time: " << sum / 10 << std::endl;

        sum = 0;
        copy_array(array, len, copy_arr);
        for (int _ = 0; _ < 10; _++)
        {
            copy_array(array, len, copy_arr);
            clock_t start = clock();
            choices_sort(copy_arr, len);
            clock_t end = clock();
            sum += (float)(end - start);
        }
        std::cout << "Choices sort time: " << sum / 10 << std::endl << std::endl;

        delete_array(array);
        delete_array(copy_arr);
    }
}
