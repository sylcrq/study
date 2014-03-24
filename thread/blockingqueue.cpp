#include "blockingqueue.h"
#include "mutexlockguard.h"

#include <iostream>

namespace syl
{

BlockingQueue::BlockingQueue() : mutex_(), cond_(mutex_)
{
    //std::cout << "BlockingQueue()" << std::endl;
}

BlockingQueue::~BlockingQueue()
{
    //std::cout << "~BlockingQueue()" << std::endl;
}

void BlockingQueue::Enqueue(int data)
{
    MutexLockGuard guard(mutex_);
    queue_.push_back(data);
    cond_.notify();
}

int BlockingQueue::Dequeue()
{
    MutexLockGuard guard(mutex_);
    while(queue_.empty())
        cond_.wait();

    int n = queue_.front();
    queue_.pop_front();
    return n;
}

} // End of namespace syl
