#ifndef CONVEYERLINE_H
#define CONVEYERLINE_H

#include <iostream>
#include <queue>
#include <mutex>
#include <ctime>
#include <thread>
#include <Windows.h>

#define STOP_FLAG -404

enum state{RUN, STOP, FINISH};

using namespace std;

class ConveyerLine
{
public:
    ConveyerLine();
    ConveyerLine(size_t line_num, size_t action_time, ConveyerLine* next);
    ConveyerLine(const ConveyerLine& copied);

    void fill_queue(int* array, int size);
    void push(int element);
    int pop();
    size_t get_size(){return elements.size();};
    void get_ended_elements();
    void start_line();
    state finish_on_line(int element);
    state process();



private:
    ConveyerLine* next;
    queue<int> elements;
    queue<int> end_elements;
    size_t line_num;


    mutex mute;

    size_t action_time;
    void action(int element);

};

#endif // CONVEYERLINE_H
