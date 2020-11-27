#include "conveyerline.h"


ConveyerLine::ConveyerLine()
{
    next = nullptr;
}

ConveyerLine::ConveyerLine(size_t line_num, size_t action_time, ConveyerLine* next)
{
    this->line_num = line_num;
    this->action_time = action_time;
    this->next = next;
}

ConveyerLine::ConveyerLine(const ConveyerLine& copied)
{
    elements = copied.elements;
    line_num = copied.line_num;
    action_time = copied.action_time;
    next = copied.next;
}


void ConveyerLine::start_line()
{
    state st = RUN;
    while (st != FINISH)
        st = process();
}

state ConveyerLine::process()
{
    int element = pop();
    //cout << "LINE NUM " << line_num << endl;
    //cout << "ELEM " << element << endl;
    if (element != NULL)
    {

        if (element == STOP_FLAG)
            return finish_on_line(element);

        action(element);

        if (next != nullptr){
            next->push(element);
            //cout << "DIO" << next->line_num << endl;
        }
        else
            end_elements.push(element);
    }
    else
        return STOP;

    return RUN;
}

void ConveyerLine::fill_queue(int *array, int size)
{
    for (int i = 0; i < size; i++)
        push(array[i]);
    push(STOP_FLAG);
}

void ConveyerLine::push(int element)
{
    mute.lock();
    elements.push(element);
    mute.unlock();
}

int ConveyerLine::pop()
{
    int element = NULL;
    mute.lock();
    int size = elements.size();
    if (size > 0)
    {
        element = elements.front();
        elements.pop();
    }
    mute.unlock();


    return element;
}

void ConveyerLine::action(int element)
{
    cout << "Line " << line_num << " | Element " << element << " ON line at " << clock() << endl;
    this_thread::sleep_for(chrono::milliseconds(action_time));
    cout << "Line " << line_num << " | Element " << element << " OUT of line at " << clock() << endl;
}

state ConveyerLine::finish_on_line(int element)
{
    if (next != nullptr)
        next->push(element);

    return FINISH;
}

void ConveyerLine::get_ended_elements()
{
    if (next == nullptr)
    {
        int len = end_elements.size();
        for (int _ = 0; _ < len; _++)
        {
            cout << end_elements.front() << " ";
            end_elements.pop();
        }
    }
    else
        cout << "Not last line!";
}
