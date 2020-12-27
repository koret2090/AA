#ifndef SEGMENT_H
#define SEGMENT_H

#include <string>
#include "consts.h"

struct segment
{
    char letter;
    std::string words[WORDS_IN_SEG];
    size_t size;
};


#endif // SEGMENT_H
