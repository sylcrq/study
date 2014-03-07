#ifndef _TEST_CHILD_
#define _TEST_CHILD_

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

class Parent;

class Child : boost::noncopyable
{
public:
    Child();
    ~Child();

    //explicit Child(Parent* p);
    explicit Child(boost::shared_ptr<Parent>& p);

private:
    //Parent* parent_;
    boost::shared_ptr<Parent> parent_;
};




#endif
