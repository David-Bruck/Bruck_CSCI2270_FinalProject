#include "Element.h"
#include <iostream>

Element::Element()
{
    LENGTH = 10;
    type = "VOID";
    track = new int[LENGTH];
    for(int i=0; i<LENGTH; i++)
    {
        track[i] = 0;
    }
}

Element::~Element()
{
    delete[] track;
}

void Element::addMarble(int m)
{
    if(inbuffer != 0)
    {
        std::cout<<"Error: Marble collision on part"<<type<<" "<<std::endl;
    }
    else
    {
        inbuffer = m;
    }
}

int Element::checkOutput()
{
    return outbuffer;
}

void Element::doOutput(int* p)
{
    *p =  outbuffer;
    outbuffer = 0;
}

int* Element::input()
{
    return &inbuffer;
}

void Element::tick()
{
    outbuffer = track[LENGTH-1];
    for(int i = LENGTH-2; i>=0; i--)
    {
        track[i+1] = track[i];
    }
    track[0] = inbuffer;
    inbuffer = 0;
}

void Element::addMarble()
{
    //Nothing, by default
}

bool Element::active()
{
    bool a = false;
    for(int i=0;i<LENGTH;i++)
    {
        if(track[i]!=0)
        {
            a = true;
            break;
        }
    }
    return a;
}
