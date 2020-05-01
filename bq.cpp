#include <iostream>
using namespace std;
#include <queue>
#include <algorithm>
#include <thread>
#include <mutex>
#include <string>
#include <condition_variable>

template <class T>
class bqueue
{
    private:
     int maxsize;
     int size;
     queue<T> Q;
     condition_variable  qfull,qempty;
    
     mutex lock; 
    
    public:
      bqueue():maxsize(0),size(0) { };
      bqueue(int n):maxsize(n),size(n) {};
      bqueue(const bqueue &obj) { maxsize = obj.maxsize();size = obj.size(); }
    
      int getsize()
      {
          size = Q.size();
          return size;
      }
      void push(const T &val)
      {
         std::unique_lock<std::mutex> lck(lock);
          
          if (Q.size() == maxsize)
            qfull.wait(lck);
         
          Q.push(val);
          qempty.notify_all();
          
      }
      int pop()
      {  
         
           std::unique_lock<std::mutex> lck(lock);
          if (Q.size()==0)
          qempty.wait(lck);
          int temp = Q.front();
          Q.pop();
          qfull.notify_all();
          return temp;
      }
      const T front()
      {
         return Q.front();
      }
    
};

void prod(bqueue<int> &Q)
{
     mutex mu;
    for(int i = 0;i<15;i++)
    {
        mu.lock();
        cout<<" Trying to enqueue "<<i<<endl;
        mu.unlock();
        Q.push(i);
        mu.lock();
        cout<<" Finished enqueuing "<<i<<endl;
        mu.unlock();
    }
}

void cons(bqueue<int> &Q)
{
     mutex mu;
    for(int i = 0;i<15;i++)
    {
        mu.lock();
        cout<<" Trying to dequeue "<<endl;
        mu.unlock();
        int temp = Q.pop();
        mu.lock();
        cout<<" Finished dequeuing "<<temp<<endl;
        mu.unlock();
    }
}

int main()
{
    bqueue<int> b(6);
   //b.push(25);
  // cout<<b.front()<<endl;
    cout<<b.getsize()<<endl;
    bqueue<string> c(3);
    cout<<c.getsize()<<endl;

    thread pd(&prod,std::ref(b));
    thread co(&cons,std::ref(b));
 pd.join();
     co.join();
   
   
    
    return 0;
}