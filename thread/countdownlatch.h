#ifndef _M_COUNTDOWN_LATCH_
#define _M_COUNTDOWN_LATCH_

#include <boost/noncopyable.hpp>

#include "condition.h"
#include "mutexlock.h"

namespace syl
{

class CountdownLatch : boost::noncopyable
{
public:
    //CountdownLatch();
    explicit CountdownLatch(int count);
    ~CountdownLatch();

    void Countdown();
    void Await();  // seconds

private:
    int count_;

    mutable MutexLock mutex_;
    Condition condition_;
};

}



#endif
