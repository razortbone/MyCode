#include <iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>
std::list<int> lis;
class oddeven
{
  
  std::mutex mu,pu;
  std::condition_variable cv;
  bool flag = false;
 public:
void funodd(list<int> &lis, int N)
 {
  pu.lock(); 
  cout<<" ODD Thread Begins size = "<<lis.size() <<endl;   
  pu.unlock();
  std::unique_lock<std::mutex> lck(mu);
     if(!(lis.size() & 1))
     {
      pu.lock(); 
      cout<<" ODD Thread waits size = "<<lis.size()<<endl; 
      pu.unlock();
      cv.wait(lck);
     }
   for(int i = 1;i<N;i=i+2)
   {
             pu.lock();
         cout<<"ODD Thread printing = "<<i<<endl;
         pu.unlock();
   lis.push_back(i);
    cv.notify_all();
      if(!(lis.size() & 1) && lis.size() <= N)
      {
        pu.lock();
        cout<<" ODD Thread waits again size = "<<lis.size()<<endl; 
        pu.unlock();
       cv.wait(lck);
      }
   }
  cv.notify_all();
   //mu.unlock();
 }
  void funeven(list<int> &lis, int N)
 {
   //mu.lock();  
   pu.lock();
   cout<<"EVEN Thread Begins size = "<<lis.size()<<endl;
   pu.unlock();
   std::unique_lock<std::mutex> lck(mu);
   if((lis.size() & 1))
   {
   cv.wait(lck);
   pu.lock();
   cout<<"EVEN Thread waits size= "<<lis.size()<<endl;
   pu.unlock();
   }
   for(int i = 0;i<N;i=i+2)
   {
        pu.lock();
         cout<<"EVEN Thread printing = "<<i<<endl;
         pu.unlock();
    lis.push_back(i);
    cv.notify_all();
       if((lis.size() & 1) && lis.size() <= N)
       {
         pu.lock();
         cout<<"EVEN Thread waits again size = "<<lis.size()<<endl;
         pu.unlock();
      cv.wait(lck);
       }
   }
  cv.notify_all();
    
    //mu.unlock();
 }
};

int main()
{
  oddeven odd;
  thread teven(&oddeven::funeven,std::ref(odd),std::ref(lis),10);
  thread todd(&oddeven::funodd,std::ref(odd),std::ref(lis),10);
  
   todd.join();
   teven.join();
   //unsigned int c = std::thread::hardware_concurrency();
    //std::cout << " number of cores: " << c << endl;;
    list<int>::iterator it;
   cout<<"List is:"<<endl;
   for(it = lis.begin(); it != lis.end();it++)
   {
       
       cout<<*it<<" ";
       cout<<endl;
   }

    return 0;
}