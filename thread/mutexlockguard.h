#ifndef _M_MUTEX_LOCK_GUARD_
#define _M_MUTEX_LOCK_GUARD_

#include <boost/noncopyable.hpp>

namespace syl
{

class MutexLock;

class MutexLockGuard : boost::noncopyable
{
public:
    //MutexLockGuard();
    ~MutexLockGuard();

    explicit MutexLockGuard(MutexLock& mutex);

private:
    MutexLock& mutex_;
};

}


#endif
