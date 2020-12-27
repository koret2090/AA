#include <iostream>
#include <string>
#include "consts.h"
#include <fstream>
#include <windows.h>

#include "dictionary.h"
#include "segdictionary.h"
#include "tests.h"

using namespace std;
void menu();

int main()
{
    menu();

    return 0;
}

void menu()
{
    int choice = -1;
    while (choice)
    {
        cout << "0 - Exit\n\
    1 - Check word\n\
    2 - Testing\n\
    Your choice: ";
        cin >> choice;
        cout << endl;

       switch (choice)
       {
       case 1:
       {
           string finding_word;
           cout << "Input your word: ";
           cin >> finding_word;

           Dictionary dic = Dictionary("C:\\Users\\User\\Documents\\AA7\\dictionary.txt");


           int res = dic.brute_force(finding_word);

           if (res >= 0)
               cout << "Result 1: " << res << " | " << "word by this index: " << dic.content[res] << endl;


           dic.sort();
           res = dic.binary_find(finding_word);

           if (res >= 0)
               cout << "Result 2: " << res << " | " << "word by this index: " << dic.content[res] << endl;

           SegDictionary seg_dict = SegDictionary(dic);
           word result = seg_dict.find_in_segment(finding_word);

           if (result.index >= 0)
               cout << "Result 3: " << "segment: " << result.segment << " | " << "index: " << result.index
                    << " | word: " << seg_dict.find_word(result) << endl;

           if (res < 0 || result.index < 0)
               cout << "No such word" << endl;
           break;
       }
       case 2:
       {
           test_brute_force();
           test_binary_find();
           test_find_in_segment();
           break;
       }
       default:
           continue;
       }
   }

}
