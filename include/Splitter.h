#ifndef SPLITTER_H
#define SPLITTER_H

#include <Element.h>


class Splitter : public Element
{
    public:
        Splitter();
        ~Splitter();
        void tick();
        bool active();
    protected:
    private:
        int* track2;
        bool r;
};

#endif // SPLITTER_H
