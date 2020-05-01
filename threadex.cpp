#include <iostream>
using namespace std;
#include <thread>
#include <mutex>
std::mutex mu;
void fun(int N)
{
  for(int i = 1; i < N; i=i+2)
  {
                mu.lock();
                std::cout<<i<<" : CHILD: Display Thread Executing  id = "<<this_thread::get_id()<<std::endl;
                mu.unlock();
  }         
}
int main()  
{
    int x = 9;
    std::thread threadObj(fun,x);
    std::cout<<"MAIN: Created child thread with id = "<<threadObj.get_id()<<endl;
    std::thread threadObj1([x]{for(int i = 0; i < x; i=i+2)
                {
                 mu.lock();
                 std::cout<<i<<": CHILD 1: Display Thread Executing  id = "<<this_thread::get_id()<<std::endl;
                mu.unlock();
                }
                });
            mu.lock();    
            std::cout<<"MAIN: Created child thread with id = "<<threadObj1.get_id()<<endl;
            mu.unlock();
    for(int i = 0; i < 5; i++)
    {
        mu.unlock();
        std::cout<<"MAIN: Display From Main Thread"<<"  id = "<<(this_thread::get_id())<<std::endl;
        mu.unlock();
    }
    threadObj.join();
    threadObj1.join();
    std::cout<<"Exiting from Main Thread"<<std::endl;
    return 0;
}