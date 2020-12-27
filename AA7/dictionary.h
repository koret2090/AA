#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include "consts.h"
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <string.h>

class Dictionary
{
public:
    Dictionary();
    Dictionary(const char* source);

    std::string content[WORDS_IN_DIC];
    size_t size;

    void print();
    void sort();
    int brute_force(std::string str);
    int binary_find(std::string str);
};

#endif // DICTIONARY_H
