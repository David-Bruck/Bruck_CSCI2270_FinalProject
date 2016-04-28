#include "Input.h"
#include <iostream>

Input::Input()
{
    LENGTH = 1;
    idcount = 1;
    type = "Input";
    track = new int[LENGTH];
    inbuffer = 0;
    outbuffer = 0;
    track[0] = 0;
}

Input::~Input()
{
    delete[] track;
}

void Input::addMarble()
{
    track[0] = idcount;
    idcount++;
}

void Input::tick()
{
    if(track[0] != 0)
    {
        std::cout<<"Marble "<<track[0]<<" entered the machine. ";
    }
    Element::tick();
}

void Input::reset()
{
    idcount = 1;
}
