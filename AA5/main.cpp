#include <iostream>
#include "conveyerline.h"

void start(int* array, int size);

using namespace std;

int main()
{
    cout << "Hello World!" << endl;


    int array[5] = {1, 2, 3, 4, 5};

    start(array, 5);



    return 0;
}


void start(int* array, int size)
{
     thread* threads = new thread[3];

     ConveyerLine line3 = ConveyerLine(3, 3000, nullptr);
     ConveyerLine line2 = ConveyerLine(2, 2000, &line3);
     ConveyerLine line1 = ConveyerLine(1, 1000, &line2);

     ConveyerLine lines[3] = {line1, line2, line3};

     line1.fill_queue(array, size);

     //for (int i = 0; i < 3; i++)
     //   threads[i] = thread(&ConveyerLine::start_line, &(lines[i]));

     threads[0] = thread(&ConveyerLine::start_line, &line1);
     threads[1] = thread(&ConveyerLine::start_line, &line2);
     threads[2] = thread(&ConveyerLine::start_line, &line3);

    for (int i = 0; i < 3; i++)
        threads[i].join();

    cout << "RESULT OBJECTS" << endl;
    line3.get_ended_elements();
}
