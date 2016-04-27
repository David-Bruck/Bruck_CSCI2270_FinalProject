#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>


class Element
{
    public:
        Element();
        virtual ~Element();
        virtual void tick();
        void addMarble(int);
        int checkOutput();
        void doOutput(int*);
        int* input();
        std::string type;
        void addMarble();
        virtual bool active();

    protected:
        int LENGTH;
        int* track;
        int inbuffer;
        int outbuffer;
};

#endif // ELEMENT_H
