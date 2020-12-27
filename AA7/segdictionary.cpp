#include "segdictionary.h"

using namespace std;

SegDictionary::SegDictionary()
{

}

SegDictionary::SegDictionary(Dictionary& dic)
{
    char alphabet[] = {'e', 't', 'a', 'o', 'i', 'n', 's', 'h', 'r', 'd', 'l', 'c',\
                      'u', 'm', 'w', 'f', 'g', 'y', 'p', 'b', 'v', 'k', 'x', 'j', \
                      'q', 'z'};

    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
        char cur_letter = alphabet[i];
        size_t amount = 0;
        segment seg;
        seg.letter = cur_letter;

        for (size_t j = 0; j < dic.size; j++)
        {
            if (dic.content[j][0] == cur_letter)
            {
                seg.words[amount] = dic.content[j];
                amount++;
            }
        }

        seg.size = amount;
        segments[i] = seg;
    }
}

void SegDictionary::print()
{
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
        cout << segments[i].letter << endl;
        for (size_t j = 0; j < segments[i].size; j++)
            cout << segments[i].words[j] << endl;
    }
}

string SegDictionary::find_word(word word)
{
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
        if (segments[i].letter == word.segment)
            return segments[i].words[word.index];
    }

    return "null";
}

word SegDictionary::find_in_segment(std::string str)
{
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
        if (segments[i].letter == str[0])
        {
            int k = 0;
            for (size_t j = 0; j < segments[i].size; j++)
            {
                if (segments[i].words[j] == str)
                {
                    word word = {segments[i].letter, k};
                    return  word;
                }
                k++;
            }
            word word = {'0', -1};
            return word;
        }
    }
    word word = {'0', -1};
    return word;
}
