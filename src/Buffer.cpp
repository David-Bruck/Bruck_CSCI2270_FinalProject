#include "Buffer.h"
#include <iostream>

Buffer::Buffer(int l)
{
    k = 0;
    LENGTH = l;
    tipped = false;
    type = "Buffer";
    track = new int[LENGTH];
    for(int i=0; i<LENGTH; i++)
    {
        track[i] = 0;
    }
    inbuffer = 0;
    outbuffer = 0;
}

Buffer::~Buffer()
{
    delete[] track;
}
void Buffer::tick()
{
    if(tipped)
    {
        outbuffer = track[LENGTH-1];
        if(outbuffer != 0)
        {
            std::cout<<"Marble "<<outbuffer<<" left buffer. ";
        }
        for(int i = LENGTH-2; i>=0; i--)
        {
            track[i+1] = track[i];
        }
        if(inbuffer != 0)
        {
            std::cout<<"Marble "<<inbuffer<<" entered buffer. ";
        }
        track[0] = inbuffer;
        inbuffer = 0;
        if(k>=LENGTH)
        {
            tipped = false;
            std::cout<<"Buffer output closed. ";
        }
        else
            k++;
    }
    else
    {
        for(int i = LENGTH-2; i>=0; i--)
        {
            if(track[i+1] == 0)
                track[i+1] = track[i];
            track[i] = 0;
        }
        if(inbuffer != 0)
        {
            std::cout<<"Marble "<<inbuffer<<" entered buffer. ";
        }
        track[0] = inbuffer;
        inbuffer = 0;
        bool a=true;
        for(int i = 0; i<LENGTH; i++)
        {
            if(track[i] == 0)
            {
                a = false;
                break;
            }
        }
        if(a)
        {
            tipped = true;
            std::cout<<"Buffer output open. ";
        }
    }
}
    bool Buffer::active()
    {
        bool a=true;
        for(int i = 0; i<LENGTH; i++)
        {
            if(track[i] == 0)
            {
                a = false;
                break;
            }
        }
        if(tipped || a)
            return true;
        else
            return false;
    }
