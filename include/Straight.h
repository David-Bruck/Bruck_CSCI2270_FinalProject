#ifndef STRAIGHT_H
#define STRAIGHT_H

#include <Element.h>


class Straight : public Element
{
    public:
        Straight(int);
        virtual ~Straight();
        void tick();
    protected:
    private:
};

#endif // STRAIGHT_H
