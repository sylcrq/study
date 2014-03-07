#include "mutexlock.h"

#include <assert.h>
#include <stdio.h>

#define MCHECK(ret) ({ __typeof__ (ret) errnum = (ret);         \
                       assert(errnum == 0); (void) errnum;})

namespace syl
{

MutexLock::MutexLock()
{
    MCHECK( pthread_mutex_init(&mutex_, NULL) );
    //printf("mutex init: %p\n", &mutex_);
}

MutexLock::~MutexLock()
{
    MCHECK( pthread_mutex_destroy(&mutex_) );
    //printf("mutex destroy: %p\n", &mutex_);
}

void MutexLock::Lock()
{
    MCHECK( pthread_mutex_lock(&mutex_) );
    //printf("mutex lock: %p\n", &mutex_);
}

void MutexLock::UnLock()
{
    MCHECK( pthread_mutex_unlock(&mutex_) );
    //printf("mutex unlock: %p\n", &mutex_);
}

} // End of namespace syl
