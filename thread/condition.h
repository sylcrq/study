#ifndef _M_CONDITION_
#define _M_CONDITION_

#include <boost/noncopyable.hpp>
#include <pthread.h>

#include "mutexlock.h"

namespace syl
{

class Condition : boost::noncopyable
{
public:
    //Condition();
    ~Condition();
    explicit Condition(MutexLock& mutex);

    void wait();
    void notify();
    void notifyAll();

private:
    pthread_cond_t condition_;

    MutexLock& mutex_;
};

}

#endif
