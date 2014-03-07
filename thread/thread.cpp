#include "thread.h"

namespace syl
{

//Thread Data Struct
struct ThreadData
{
    boost::function<void()> func_;

    ThreadData(boost::function<void()>& f) : func_(f)
    {}

    void run()
    {
        func_();
    }
};

void* startThread(void* obj)
{
    ThreadData* data = static_cast<ThreadData*>(obj);
    data->run();
    delete data;
    return NULL;
}

//Thread::Thread()
//{}

Thread::~Thread()
{}

Thread::Thread(ThreadFunc& f)
 : pthreadid_(0),
   func_(f)
{}

void Thread::Start()
{
    ThreadData* data = new ThreadData(func_);

    if(pthread_create(&pthreadid_, NULL, &startThread, data) != 0)
    {
        std::cerr << "create thread failed" << std::endl;
        delete data;
    }
}

void Thread::Join()
{
    if(pthread_join(pthreadid_, NULL) != 0)
    {
        std::cerr << "join thread failed" << std::endl;
    }
}

} // End of namespace syl
