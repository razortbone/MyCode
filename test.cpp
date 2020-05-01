#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
int A = 0;
#define N 10
mutex mu;
condition_variable o,e;
void task(int num,int s)
{
    sleep(s);
    cout<<num<<endl;
}

void printfun()
{
    //int i;
    for (int i=0; i < N;i++)
    {
        task(i,1);
    }
    cout<<endl;
}
void t1fun()
{
    std::unique_lock<std::mutex> lck(mu);
    cout<<"t1fun "<<A<<endl;

    for(;A<N;A=A+1)
    {
    if (A&1)
    o.wait(lck);
    if (!(A&1))
    task(A,1);
    e.notify_all();
    }

}
void t2fun()
{
    std::unique_lock<std::mutex> lck(mu);
    cout<<"t2fun "<<A<<endl;

    for(;A<N;A=A+1)
    {
    if (!(A&1))
    e.wait(lck);
    if (A&1)
    task(A,1);
    o.notify_all();
    }

}
int main()
{
    int num = 0;
    //printfun();
    thread t1(t1fun);
    thread t2(t2fun);
    t1.join();
    t2.join();
    return 0;
}