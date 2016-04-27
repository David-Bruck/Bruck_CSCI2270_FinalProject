#ifndef BUFFER_H
#define BUFFER_H

#include <Element.h>


class Buffer : public Element
{
    public:
        Buffer(int);
        virtual ~Buffer();
        void tick();
        bool active();
    protected:
    private:
        bool tipped;
        int k;
};

#endif // BUFFER_H
