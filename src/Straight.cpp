#include "Straight.h"

Straight::Straight(int l)
{
    LENGTH = l;
    type = "Straight";
    track = new int[LENGTH];
    for(int i=0; i<LENGTH; i++)
    {
        track[i] = 0;
    }
    inbuffer = 0;
    outbuffer = 0;
}

Straight::~Straight()
{
    delete[] track;
}

void Straight::tick()
{
    Element::tick();
}
