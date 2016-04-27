#include "Buffer.h"

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
        for(int i = LENGTH-2; i>=0; i--)
        {
            track[i+1] = track[i];
        }
        track[0] = inbuffer;
        inbuffer = 0;
        if(k>=LENGTH)
            tipped = false;
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
            tipped = true;
    }
}

bool Buffer::active()
{
    return tipped;
}
