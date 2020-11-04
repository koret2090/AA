#include "array.h"

using namespace std;

int* create_array(int size)
{
    int* array = new int [size];

    return array;
}

void delete_array(int* array)
{
    delete [] array;
}

void fill_array_with_random_nums(int* array, int size)
{
    for(int i = 0; i < size; i++)
        array[i] = rand();
}

void print_array(int* array, int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i]<< " ";
    cout << endl;
}

void input_array(int* array, int size)
{
    cout << "Input array" << endl;
    for(int i = 0; i < size; i++)
        cin >> array[i];
    cout << endl;
}

void copy_array(int* array, int size, int* dest_arr)
{
    for (int i = 0; i < size; i++)
        dest_arr[i] = array[i];
}
