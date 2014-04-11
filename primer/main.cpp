#include <iostream>
#include <string>

class Test
{
public:
    explicit Test(std::string name):name_(name) { std::cout << "Test() - " << name_ << std::endl; }
    ~Test() { std::cout << "~Test() - " << name_ << std::endl; }

private:
    std::string name_;
};

//global variable
//non-local static object
Test t1("t1");

namespace test
{
//non-local static object
Test t2("t2");
}

void f()
{
    //local static object
    static Test t4("t4");
}


int main()
{
    std::cout << "main start" << std::endl;

    //f();

    //local static object
    static Test t3("t3");    

    std::cout << "main end" << std::endl;
    return 0;
}
