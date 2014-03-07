#ifndef _M_THREAD_BASE_
#define _M_THREAD_BASE_

#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

#include <pthread.h>


namespace syl
{

class Thread : boost::noncopyable
{
public:
    typedef boost::function<void()> ThreadFunc;

    //Thread();
    ~Thread();

    explicit Thread(ThreadFunc& f);

    void Start();
    void Join();

private:
    pthread_t pthreadid_;
    ThreadFunc func_;
};

}

#endif

