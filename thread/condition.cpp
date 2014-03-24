#include <iostream>

#include "condition.h"


namespace syl
{

//Condition::Condition()
//{
//    std::cout << "Condition()" << std::endl;
//    pthread_cond_init(&condition_, NULL);
//}


Condition::~Condition()
{
    //std::cout << "~Condition()" << std::endl;
    pthread_cond_destroy(&condition_);
}

Condition::Condition(MutexLock& mutex) : mutex_(mutex)
{
    //std::cout << "Condition(MutexLock&)" << std::endl;
    pthread_cond_init(&condition_, NULL);
}

void Condition::wait()
{
    pthread_cond_wait(&condition_, &(mutex_.mutex_));
}

void Condition::notify()
{
    pthread_cond_signal(&condition_);
}

void Condition::notifyAll()
{
    pthread_cond_broadcast(&condition_);
}

} // End of namespace syl
