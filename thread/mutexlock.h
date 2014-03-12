#ifndef _M_MUTEX_LOCK_
#define _M_MUTEX_LOCK_

#include <boost/noncopyable.hpp>
#include <pthread.h>

namespace syl
{

class MutexLock : boost::noncopyable
{
public:
    MutexLock();
    ~MutexLock();

    friend class Condition;

    void Lock();
    void UnLock();

private:
    pthread_mutex_t mutex_;
};

}


#endif
