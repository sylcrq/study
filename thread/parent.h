#ifndef _TEST_PARENT_
#define _TEST_PARENT_

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

class Child;

class Parent : boost::noncopyable
{
public:
    Parent();
    ~Parent();

    //void SetChild(Child* c);
    void SetChild(boost::shared_ptr<Child>& c);

private:
    //Child* child_;
    //boost::shared_ptr<Child> child_;
    boost::weak_ptr<Child> child_;
};


#endif
