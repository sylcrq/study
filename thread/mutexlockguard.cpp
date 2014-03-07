#include "mutexlock.h"
#include "mutexlockguard.h"

#include <stdio.h>

namespace syl
{

//MutexLockGuard::MutexLockGuard()
//{}

MutexLockGuard::~MutexLockGuard()
{
    //printf("~MutexLockGuard()\n");
    mutex_.UnLock();
}

MutexLockGuard::MutexLockGuard(MutexLock& mutex) : mutex_(mutex)
{
    //printf("MutexLockGuard(MutexLock&)\n");
    mutex_.Lock();
}

} // End of namespace syl

