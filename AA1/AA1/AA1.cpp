#include <iostream>
#include <cstring>
#include <algorithm>

#include "recursion.h"
#include "table.h"
#include "damerau.h"
#include "table_n_recursion.h"
#include "tests.h"

using namespace std;
void menu();

int main()
{
    cout << "Hello World!" << endl;

    menu();

    return 0;
}

void menu()
{
    char str1[256] = "";
    char str2[256] = "";

    int choice = -1;
    long int answer = 0;
    while (choice)
    {
        cout << "0 - Exit\n\
1 - Input strings\n\
2 - Levenshtein with matrix\n\
3 - Levenshtein recursive\n\
4 - Levenshtein recursive with matrix\n\
5 - Damerau-Levenshtein with matrix\n\
6 - Timing tests\n\
Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Input first str: ";
            std::cin.getline(str1, 256);
            cout << "Input second str: ";
            std::cin.getline(str2, 256);
            getchar();
            break;
        case 2:
            answer =  levenshtein_distance(str1, str2);
            cout << "Answer: " << answer << endl;
            getchar();
            break;
        case 3:
            answer = levenshtein_recursion(str1, str2);
            cout << "Answer: " << answer << endl;
            getchar();
            break;
        case 4:
            answer = levenshtein_table_n_recursion(str1, str2);
            cout << "Answer: " << answer << endl;
            getchar();
            break;
        case 5:
            answer = damerau_levenshtein_distance(str1, str2);
            cout << "Answer: " << answer << endl;
            getchar();
            break;
        case 6:
            test();
            getchar();
            break;
        default:
            continue;
        }
    }

    //test();
}










// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
