#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>


int* create_array(int size);
void delete_array(int* array);
void fill_array_with_random_nums(int* array, int size);
void print_array(int* array, int size);
void input_array(int* array, int size);
void copy_array(int* array, int size, int* dest_arr);

#endif // ARRAY_H
