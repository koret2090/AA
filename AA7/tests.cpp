#include "tests.h"

using namespace std;

void test_brute_force()
{
    Dictionary dic = Dictionary("C:\\Users\\User\\Documents\\AA7\\dictionary.txt");

    ofstream file ("brute_force.dat");

    for (size_t i = 0; i < dic.size; i += 50)
    {
        float sum = 0;
        string str = dic.content[i];
        for (int j = 0; j < 1000; j++)
        {
            clock_t start = clock();
            dic.brute_force(str);
            clock_t end = clock();
            sum += (float)(end - start);
        }
        sum /= 1000;
        file << i + 1 << " " << sum << endl;
        cout << i << " " << str << endl;
    }
    file.close();
}

void test_binary_find()
{
    Dictionary dic = Dictionary("C:\\Users\\User\\Documents\\AA7\\dictionary.txt");
    dic.sort();

    ofstream file ("binary_find.dat");

    for (size_t i = 0; i < dic.size; i += 50)
    {
        float sum = 0;
        string str = dic.content[i];
        for (int j = 0; j < 1000; j++)
        {
            clock_t start = clock();
            dic.binary_find(str);
            clock_t end = clock();
            sum += (float)(end - start);
        }
        sum /= 1000;
        file << i + 1 << " " << sum << endl;
        cout << i << " " << str << endl;
    }
    file.close();
}

void test_find_in_segment()
{
    Dictionary dic = Dictionary("C:\\Users\\User\\Documents\\AA7\\dictionary.txt");
    dic.sort();
    SegDictionary seg_dic = SegDictionary(dic);

    ofstream file ("find_in_segment.dat");

    for (size_t i = 0; i < dic.size; i += 50)
    {
        float sum = 0;
        string str = dic.content[i];
        word res = {'a', 0};
        for (int j = 0; j < 1000; j++)
        {
            clock_t start = clock();
            res = seg_dic.find_in_segment(str);
            clock_t end = clock();
            sum += (float)(end - start);
        }
        sum /= 1000;
        file << i + 1 << " " << sum << endl;
        cout << i << " " << str << endl;
    }
    file.close();
}
