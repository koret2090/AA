#include "array.h"
#include "sorts.h"
#include "tests.h"

void menu();

using namespace std;

int main()
{
    /*
    cout << "Hello World!" << endl;

    int size = 10;
    int* arr = create_array(size);
    fill_array_with_random_nums(arr, size);
    print_array(arr, size);

    bubble_sort(arr, size);
    print_array(arr, size);
    fill_array_with_random_nums(arr, size);
    print_array(arr, size);

    insertion_sort(arr, size);
    print_array(arr, size);
    fill_array_with_random_nums(arr, size);
    print_array(arr, size);

    choices_sort(arr, size);
    print_array(arr, size);

    delete_array(arr);
    */
    menu();

    return 0;
}

void menu()
{
    int size = 0;
    int choice = -1;

    int* array = nullptr;
    int* copy_arr = nullptr;

    while (choice)
    {
        cout << "0 - Exit\n\
1 - Input array\n\
2 - Bubble\n\
3 - Insertion\n\
4 - Choices\n\
5 - Timing tests\n\
Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Input size: ";
            cin >> size;

            copy_arr = create_array(size);
            array = create_array(size);
            input_array(array, size);
            break;
        case 2:
            copy_array(array, size, copy_arr);
            bubble_sort(copy_arr, size);
            print_array(copy_arr, size);
            break;
        case 3:
            copy_array(array, size, copy_arr);
            insertion_sort(copy_arr, size);
            print_array(copy_arr, size);
            break;
        case 4:
            copy_array(array, size, copy_arr);
            choices_sort(copy_arr, size);
            print_array(copy_arr, size);
            break;
        case 5:
            test();
            break;
        default:
            continue;
        }
    }

    delete_array(array);
    //test();
}
