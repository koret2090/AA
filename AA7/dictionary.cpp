#include "dictionary.h"

using namespace std;

Dictionary::Dictionary()
{
    size = 0;
}

Dictionary::Dictionary(const char* source)
{
    size = 0;
    string line;
    ifstream file(source);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            content[size] = line;
            size++;
        }
    }

    file.close();
}

void Dictionary::print()
{
    for (size_t i = 0; i < size; i++)
        cout << content[i] << endl;
}

void Dictionary::sort()
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1 - i; j++)
        {
            if (content[j] > content[j+1])
            {
                string swap = content[j];
                content[j] = content[j+1];
                content[j+1] = swap;
            }
        }
    }
}

int Dictionary::brute_force(std::string str)
{
    for (size_t i = 0; i < size; i++)
    {
        if (str == content[i])
            return i;
    }

    return -1;
}

int Dictionary::binary_find(std::string str)
{
    int left = 0;
    int right = size;
    int mid = 0;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if (str < content[mid])
            right = mid - 1;
        else if (str > content[mid])
            left = mid + 1;
        else return  mid;
    }
    return -(1 + left);
}
