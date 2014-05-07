#ifndef _PAINTER_H_
#define _PAINTER_H_

#include "Turtle.h"

class Painter
{
public:
    Painter(Turtle* t):turtle_(t) {}

    bool DrawCircle(int x, int y, int z) 
    { 
        turtle_->PenDown(); 
        return true;
    }

private:
    Turtle* turtle_;
};


#endif
