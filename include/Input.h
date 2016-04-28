#ifndef INPUT_H
#define INPUT_H

#include <Element.h>


class Input : public Element
{
    public:
        Input();
        ~Input();
        void addMarble();
        void tick();
        void reset();
    protected:
    private:
        int idcount;
};

#endif // INPUT_H
