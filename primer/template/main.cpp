#include <iostream>
#include <string>
#include <list>

#if 0
template <class T>
class MQueue
{
public:
    T& dequeue();
    void enqueue(T&);

    int size();
private:
    std::list<T> mqueue_;
};
#endif


template <typename T>
int compare(const T& a, const T& b)
{
    if(a > b)
        return 1;
    else if(a < b)
        return -1;
    else
        return 0;
}


int main()
{
    std::cout << compare(1, 1) << std::endl;
    std::cout << compare(1.0, 2.8) << std::endl;

    std::string sa("hello");
    std::string sb("world");
    std::cout << compare(sb, sa) << std::endl;

    return 0;
}
