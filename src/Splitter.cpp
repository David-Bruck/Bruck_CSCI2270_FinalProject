#include "Splitter.h"
#include <iostream>

Splitter::Splitter()
{
    LENGTH = 10;
    r = false;
    type = "Split/Join";
    track = new int[LENGTH];
    track2 = new int[LENGTH];
    for(int i=0; i<LENGTH; i++)
    {
        track[i] = 0;
        track2[i] = 0;
    }
    inbuffer = 0;
    outbuffer = 0;
}

Splitter::~Splitter()
{
    delete[] track;
    delete[] track2;
}

void Splitter::tick()
{
    if(track[LENGTH-1]!=0)
    {
        outbuffer = track[LENGTH-1];
        track[LENGTH-1] = 0;
    }
    else
    {
        outbuffer = track2[LENGTH-1];
        track2[LENGTH-1] = 0;
    }
    if(outbuffer != 0)
    {
        std::cout<<"Marble "<<outbuffer<<" left splitter. ";
    }
    for(int i = LENGTH-2; i>=0; i--)
    {
        track[i+1] = track[i];
        track2[i+1] = track2[i];
        track[i] = 0;
        track2[i] = 0;
    }
    if(!r && inbuffer)
    {
        std::cout<<"Marble "<<inbuffer<<" entered splitter left branch. ";
        track[0] = inbuffer;
        inbuffer = 0;
        r = !r;
    }
    else if(r && inbuffer)
    {
        std::cout<<"Marble "<<inbuffer<<" entered splitter right branch. ";
        track2[0] = inbuffer;
        inbuffer = 0;
        r = !r;
    }
}

bool Splitter::active()
{
    bool a = false;
    for(int i=0;i<LENGTH;i++)
    {
        if(track[i]!=0 || track2[i]!=0)
        {
            a = true;
            break;
        }
    }
    return a;
}
