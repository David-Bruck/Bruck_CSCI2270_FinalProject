#include "Output.h"
#include <iostream>

Output::Output()
{
    LENGTH = 1;
    type = "Output";
    track = new int[LENGTH];
    track[0] = 0;
    inbuffer = 0;
    outbuffer = 0;
}

Output::~Output()
{
    delete[] track;
}

void Output::tick()
{
    if(inbuffer!=0)
    {
        std::cout<<"Marble "<<inbuffer<<" left the machine. ";
    }
    inbuffer = 0;
}
