#ifndef OUTPUT_H
#define OUTPUT_H

#include <Element.h>


class Output : public Element
{
    public:
        Output();
        ~Output();
        void tick();
};

#endif // OUTPUT_H
