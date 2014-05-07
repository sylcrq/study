#include "MockTurtle.h"
#include "Painter.h"
//#include "gmock/gmock.h"
//#include "gtest/gtest.h"

//1. Import the Google Mock names from the testing namespace such that you can use them unqualified 
//   (You only have to do it once per file. Remember that namespaces are a good idea and good for your health.).
//2. Create some mock objects.
//3. Specify your expectations on them 
//   (How many times will a method be called? With what arguments? What should it do? etc.).
//4. Exercise some code that uses the mocks; optionally, check the result using Google Test assertions. 
//   If a mock method is called more than expected or with wrong arguments, you'll get an error immediately.
//5. When a mock is destructed, Google Mock will automatically check whether all expectations on it have been satisfied.

using ::testing::AtLeast;                       // #1

TEST(PainterTest, CanDrawSomething) {
    MockTurtle turtle;                          // #2

    EXPECT_CALL(turtle, PenDown())              // #3
        .Times(AtLeast(1));

    Painter painter(&turtle);                   // #4

    EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
}                                               // #5



