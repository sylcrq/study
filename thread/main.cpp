#include <iostream>
#include <sys/syscall.h>

#include "child.h"
#include "parent.h"

#include "condition.h"
#include "mutexlock.h"
#include "mutexlockguard.h"
#include "thread.h"

using namespace syl;

MutexLock g_mutex;
Condition g_condition(g_mutex);
volatile int g_counter = 0;

void mythreadFunc()
{
    std::cout << "tid: " << syscall(SYS_gettid) << std::endl;
    std::cout << "pthread id: " << pthread_self() << std::endl;

    int i = 10;
    while(i > 0) {
        MutexLockGuard m(g_mutex);
        //g_mutex.Lock();
        std::cout << "I am " << i << std::endl;
        i--;
        //g_mutex.UnLock();
    }
}

namespace detail
{
void foo()
{
    std::cout << "foo" << std::endl;
}
}

void consumer()
{
    while(1)
    {
        MutexLockGuard guard(g_mutex);
        while(g_counter == 0)
            g_condition.wait();
        std::cout << "I am alive " << g_counter << std::endl;
        g_counter--;
    }
}

void producer()
{
    MutexLockGuard guard(g_mutex);
    g_counter++;
    g_condition.notify();
}

int main()
{
    boost::function<void()> f;
    f = boost::bind(&consumer);
    Thread thread2(f);

    thread2.Start();

    while(1) {
        producer();
        sleep(5);
    }
#if 0
    boost::shared_ptr<Parent> parent(new Parent());
    boost::shared_ptr<Child> child(new Child(parent));
    parent.get()->SetChild(child);

    std::cout << "parent: " << parent.use_count() << std::endl;
    std::cout << "child: " << child.use_count() << std::endl;
#endif

#if 0
    Parent* parent = new Parent();
    Child* child = new Child(parent);

    parent->SetChild(child);

    delete child;
    delete parent;
#endif

//    detail::foo();

#if 0
    std::cout << "enter main" << std::endl;

    boost::function<void()> f;
    f = boost::bind(&mythreadFunc);

    Thread thread1(f);
    thread1.Start();

    {
        MutexLockGuard m(g_mutex);
        //g_mutex.Lock();
        std::cout << "i am main" << std::endl;
        //g_mutex.UnLock();
    }

    thread1.Join();
    //sleep(5);
    std::cout << "main exit" << std::endl;
#endif
    return 0;
}
