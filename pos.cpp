#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <cctype>

bool isOperator(char ch)
{
    if (ch == '+'||ch == '-'||ch == '*'||ch =='/')
    return true;

    return false;
}
float eval(float a, float b, char op)
{
    switch(op)
    {
       case '+': return a+b;
       case '-': return a-b;
       case '*': return a*b;
       case '/': return a/b;
    };
    return 0;
}
float evaluatePostfix(char exp[])
{
  int n = strlen(exp);
  stack<float> s;
  for(int i = 0;i<n;i++)
  {
      if (isdigit(exp[i]))
      {
          string val;
          val.push_back(exp[i]);
          int a = std::stoi(val);
          s.push(a);
      }
      else if (isOperator(exp[i]))
      {
          if(s.size()>1)
          {
               float ft = s.top();
               s.pop();
               float se = s.top();
               s.pop();
               cout<<ft<<" "<<se<<endl;
               s.push(eval(ft,se,exp[i]));
          }
          else
          {
              cout<<"Invalid postfix expression"<<endl;
              return -1;
          }
      }
      else
      {
            cout<<"Invalid postfix expression"<<endl;
            return -1;
      }
  }
  if(s.size()>0)
  return s.top();
 
  return -1;
}

int main()  
{  
    char exp[] = "231*+9-";  
    cout<<"postfix evaluation: "<< evaluatePostfix(exp)<<endl;  
    return 0;  



    
}
