#ifndef MARBLEMACHINE_H
#define MARBLEMACHINE_H
#include "Element.h"
#include <vector>
#include <string>

class MarbleMachine
{
public:
    MarbleMachine();
    ~MarbleMachine();
    void addElement(int);
    void popElement();
    void clearMachine();
    void print();
    void runRD(int,int);
    void runND(int,int);
    void runRN(int,int);
    bool closed();
    void tick();
    void addMarble();


protected:
    std::vector<Element*> machine;
private:
    int straight;
    int buffer;
    int splitter;
};
#endif // MARBLEMACHINE_H
