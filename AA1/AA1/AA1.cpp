#include <iostream>
#include <cstring>
#include <algorithm>

#include "recursion.h"
#include "table.h"
#include "damerau.h"
#include "table_n_recursion.h"
#include "tests.h"

using namespace std;


int main()
{
    cout << "Hello World!" << endl;

    char str1[256];
    char str2[256];
   
    cout << "Input first str: ";
    cin >> str1;
    cout << "Input second str: ";
    cin >> str2;


    
    size_t ans = levenshtein_distance(str1, str2);

    cout << "ANSWER1: " << ans << endl;

    ans = levenshtein_recursion(str1, str2);
    cout << "ANSWER2: " << ans << endl;
    
    
    ans = damerau_levenshtein_distance(str1, str2);
    cout << "ANSWER3: " << ans << endl;

    ans = levenshtein_table_n_recursion(str1, str2);
    cout << "ANSWER4: " << ans << endl;
   
    test();


    return 0;
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
