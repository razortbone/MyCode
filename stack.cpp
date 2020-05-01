#include <iostream>
#include <stdexcept>    
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;



template<class T>
class myStack
{
   private:
   vector<T> arr;
   public:

   T top() const;
   void isEmpty();
   void pop();
   void push(T const &);
};

template<class T>  void myStack<T>::push(T const & val)
{
    arr.push_back(val);
}

template<class T> T myStack<T>::top() const
{
    return arr[0];
}
template<class T> void myStack<T>::pop() 
{
    arr.pop_front();
}
int main() 
{ 
 try { 
  myStack<int> myIntegerStack; // stack of ints 
  myStack<string> myStringStack; // stack of strings
  myIntegerStack.push(10); 
       cout << myIntegerStack.top() <<endl;
myStringStack.push("Messi");
cout << myStringStack.top() << std::endl;
}
catch (exception const& ex) {
cerr << "Exception: " << ex.what() <<endl;
return -1;
}
}