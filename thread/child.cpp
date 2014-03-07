#include "child.h"
#include "parent.h"

#include <iostream>

Child::Child()
{
    std::cout << "Child()" << std::endl;
}

Child::~Child()
{
    std::cout << "~Child()" << std::endl;
}


//Child::Child(Parent* p) : parent_(p)
Child::Child(boost::shared_ptr<Parent>& p) : parent_(p)
{
    std::cout << "Child(Parent*)" << std::endl;
}
