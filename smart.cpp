#include <iostream>
using namespace std;
template<class T>

class smart
{
    public:
   T* ptr;
   int *ref_count ;

   explicit smart( T *p = NULL) 
   {
       ptr = p;
   }

   ~smart() 
  {
      delete ptr;
  }

   T & operator * () {return *ptr;}
  
   T * operator -> () {return ptr;}

   T  operator = () {return ptr;}

};

int main()
{
   int a = 5;
   int *val = &a;

   smart<int> p(new int());
   *p = 2;
   smart<int> q = p;
   cout<<*p<<" "<<endl;

    return 0;
}
