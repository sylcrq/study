#include "countdownlatch.h"
#include "mutexlockguard.h"

namespace syl
{

CountdownLatch::CountdownLatch(int count)
 : count_(count), 
   mutex_(),
   condition_(mutex_)
{}

CountdownLatch::~CountdownLatch()
{}


void CountdownLatch::Countdown()
{
    MutexLockGuard lock(mutex_);
    if(count_ > 0)
    {
        count_--;
        if(count_ == 0)
            condition_.notifyAll(); // notify all other waiting thread
    }
}

void CountdownLatch::Await()
{
    MutexLockGuard lock(mutex_);
    while(count_ > 0)
        condition_.wait();
}


} // End of namespace syl

