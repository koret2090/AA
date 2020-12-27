#ifndef SEGDICTIONARY_H
#define SEGDICTIONARY_H

#include "segment.h"
#include "dictionary.h"
#include "word.h"

class SegDictionary
{
public:
    SegDictionary();
    SegDictionary(Dictionary& dic);

    segment segments[ALPHABET_SIZE];

    void print();
    std::string find_word(word word);
    word find_in_segment(std::string word);
};

#endif // SEGDICTIONARY_H
