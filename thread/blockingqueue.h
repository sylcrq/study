#ifndef _M_BLOCKING_QUEUE_
#define _M_BLOCKING_QUEUE_

#include <boost/noncopyable.hpp>
#include <deque>

#include "condition.h"
#include "mutexlock.h"

namespace syl
{

//CAN NOT use forward declaration here
//class MutexLock;
//class Condition;

class BlockingQueue : boost::noncopyable
{
public:
    BlockingQueue();
    ~BlockingQueue();

    void Enqueue(int data);
    int Dequeue();

private:
    //Note: the order of MutexLock and Condition
    //MutexLock mutex_;
    mutable MutexLock mutex_;
    Condition cond_;

    //std::vector<int> queue_;
    std::deque<int> queue_;
};

}


#endif
