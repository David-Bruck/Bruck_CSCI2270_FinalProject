#include "MarbleMachine.h"
#include "Element.h"
#include "Input.h"
#include "Output.h"
#include "Splitter.h"
#include "Buffer.h"
#include "Straight.h"
#include <iostream>
#include <unistd.h>


MarbleMachine::MarbleMachine()
{
    machine.push_back(new Input);
}

MarbleMachine::~MarbleMachine()
{
    //dtor
}

void MarbleMachine::addElement(int type)
{
    Element* e;
    switch(type)
    {
    case 1:
    {
        e = new Straight(5);
        break;
    }
    case 2:
    {
        e = new Straight(10);
        break;
    }
    case 3:
    {
        e = new Buffer(5);
        break;
    }
    case 4:
    {
        e = new Buffer(10);
        break;
    }
    case 5:
    {
        e = new Splitter;
        break;
    }
    case 6:
    {
        e = new Output;
        break;
    }
    default:
    {
        std::cout<<"Invalid Element ID"<<std::endl;
        return;
    }
    }
    machine.push_back(e);
}

void MarbleMachine::popElement()
{
    if(machine.size()<2)
    {
        std::cout<<"No more removable parts."<<std::endl;
        return;
    }
    std::cout<<machine[machine.size()-1]->type<<" "<<" removed."<<std::endl;
    machine.erase(machine.begin()+(machine.size()-1));
}

void MarbleMachine::tick()
{
    for(unsigned i=0; i<machine.size()-1; i++)
    {
        machine[i]->tick();
        machine[i]->doOutput(machine[i+1]->input());
    }
    machine[machine.size()-1]->tick();
}

void MarbleMachine::print()
{
    if(machine.size()>1)
    {
        for(int i=0; i<machine.size()-1; i++)
        {
            std::cout<<machine[i]->type<<"-";
        }
    }
    {
        std::cout<<machine[machine.size()-1]->type;
    }
    std::cout<<std::endl;
}

bool MarbleMachine::closed()
{
    return (*machine.back()).type == "Output";
}

void MarbleMachine::addMarble()
{
    ((Input*)(machine[0]))->addMarble();
}

void MarbleMachine::runRD(int rate, int dur)
{
    double d = 1/(double)rate;
    double f = 0;
    int j = 0;
    int i;
    for(i=0; i<dur*10; i++)
    {
        f+=0.1;
        j++;
        if(f>=d)
        {
            f-=j*0.1;
            j = 0;
            this->addMarble();
        }
        std::cout<<"["<<i*0.1<<"] ";
        this->tick();
        std::cout<<std::endl;
        usleep(100000);
    }
    bool g;
    while(g)
    {
        g = false;
        std::cout<<"["<<i*0.1<<"] ";
        this->tick();
        std::cout<<std::endl;
        i++;
        usleep(100000);
        for(int j=0; j<machine.size(); j++)
        {
            if(machine[j]->active())
            {
                g = true;
                break;
            }
        }
    }
}

void MarbleMachine::runND(int num, int dur)
{
    double d = (double)num/(double)dur;
    double f = 0;
    int j = 0;
    for(int i=0; i<=dur*10; i++)
    {
        f+=0.1;
        j++;
        if(f>=d)
        {
            f-=j*0.1;
            j = 0;
            this->addMarble();
        }
        std::cout<<"["<<i*0.1<<"] ";
        this->tick();
        std::cout<<std::endl;
        usleep(100000);
    }
}

void MarbleMachine::runRN(int rate, int num)
{
    double d = 1/(double)rate;
    double f = 0;
    double dur = (double)num/(double)rate;
    int j = 0;
    for(int i=0; (double)i<=dur*10; i++)
    {
        f+=0.1;
        j++;
        if(f>=d)
        {
            f-=j*0.1;
            j = 0;
            this->addMarble();
        }
        std::cout<<"["<<i*0.1<<"] ";
        this->tick();
        std::cout<<std::endl;
        usleep(100000);
    }
}
