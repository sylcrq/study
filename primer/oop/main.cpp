#include <iostream>
#include <string>

class Base
{
public:
    Base() { std::cout << "Base()" << std::endl; }
    //base class destructor should be virtual
    virtual ~Base() { std::cout << "~Base()" << std::endl; }

    int GetNum() { std::cout << "Base::GetNum()" << std::endl; }

    //dynamic binding
    virtual void GetName() { std::cout << "Base::GetName()" << std::endl; }
private:
    //int num_;
};

class Derive : public Base
{
public:
    Derive() { std::cout << "Derive()" << std::endl; }
    ~Derive() { std::cout << "~Derive()" << std::endl; }

    int GetNum() { std::cout << "Derive::GetNum()" << std::endl; }

    virtual void GetName() { std::cout << "Derive::GetName()" << std::endl; }
private:
    //int 
};


int main()
{
    //Base b;

    //Derive d;

    //Base* b = new Base();
    Base* b1 = new Base();
    Base* b2 = new Derive();

    b1->GetNum();
    b1->GetName();
    b2->GetNum();
    b2->GetName();

    delete b1;
    delete b2;
    return 0;
}
