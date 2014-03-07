#include "child.h"
#include "parent.h"

#include <iostream>

Parent::Parent()
{
    std::cout << "Parent()" << std::endl;
}


Parent::~Parent()
{
    std::cout << "~Parent()" << std::endl;
}


//void Parent::SetChild(Child* c)
void Parent::SetChild(boost::shared_ptr<Child>& c)
{
    std::cout << "SetChild(Child*)" << std::endl;
    child_ = c;
}
