#include "sorts.h"

void bubble_sort(int* array, int size)
{
    if (size <= 0)
    {
        std::cout << "Incorrect array" << std::endl;
        return;
    }

    for (int i = 0; i < size - 1; i++)
    {
       for (int j = 0; j < size - i - 1; j++)
       {
           if (array[j] > array[j + 1])
           {
               int temp = array[j];
               array[j] = array[j + 1];
               array[j + 1] = temp;
           }
       }
    }
}

void insertion_sort(int *array, int size)
{
    if (size <= 0)
    {
        std::cout << "Incorrect array" << std::endl;
        return;
    }

    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int item = i - 1;
        while(item >= 0 && array[item] > temp)
        {
            array[item + 1] = array[item];
            array[item] = temp;
            item--;
        }
    }
}

void choices_sort(int* array, int size)
{
    if (size <= 0)
    {
        std::cout << "Incorrect array" << std::endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        int temp = array[0];
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
