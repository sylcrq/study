#ifndef _MOCK_TURTLE_H_
#define _MOCK_TURTLE_H_

#include "Turtle.h"
#include "gmock/gmock.h"  // Brings in Google Mock.

//1. Derive a class MockTurtle from Turtle.
//2. Take a virtual function of Turtle (while it's possible to mock non-virtual methods using templates, it's much more involved). Count how many arguments it has.
//3. In the public: section of the child class, write MOCK_METHODn(); (or MOCK_CONST_METHODn(); 
//   if you are mocking a const method), where n is the number of the arguments; 
//   if you counted wrong, shame on you, and a compiler error will tell you so.
//4. Now comes the fun part: you take the function signature, cut-and-paste the function name as the first argument to the macro, 
//   and leave what's left as the second argument (in case you're curious, this is the type of the function).
//5. Repeat until all virtual functions you want to mock are done.

class MockTurtle : public Turtle {
public:
    MOCK_METHOD0(PenUp, void());
    MOCK_METHOD0(PenDown, void());
    MOCK_METHOD1(Forward, void(int distance));
    MOCK_METHOD1(Turn, void(int degrees));
    MOCK_METHOD2(GoTo, void(int x, int y));
    MOCK_CONST_METHOD0(GetX, int());
    MOCK_CONST_METHOD0(GetY, int());
};

#endif
