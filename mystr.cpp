#include <iostream>
using namespace std;
class mystr
{
  private:
     char *str;
     int size;
  public:
     mystr()
     {
         size = 0;
     }
     mystr(int s)
     {
         cout<<"\nCalling p contructor for size = "<<s<<endl;
         size = s;
         str = new char[size+1];
     }
     mystr(const char *t)
     {
       cout<<"\nCalling contructor for "<<t<<endl;
       size = strlen(t);
       str = new char[size+1];
       strcpy(str,t);
     }
     mystr(const mystr &obj)
     {
         cout<<"\nCalling copy contructor for "<<obj.str<<endl;
         size = obj.size;
         str = new char[size+1];
         strcpy(str,obj.str);
     }

     ~mystr()
     {
         cout<<"\nCalling destructor for "<<str<<endl;
         delete []str;
     }
     void display()
     {
         cout<<str<<endl;
         cout<<"string length = "<<size<<endl;
     }
     mystr operator +(mystr const &obj)
     {  
         cout<<" now "<<endl;
         
         char *temp = new char[size];
         strcpy(temp,str);
         delete []str;
         
         mystr res(size+obj.size);
         strcpy(str,temp);
         for(int j = 0;j<obj.size;j++)
         {
            res.str[strlen(temp)+j] = obj.str[j];
         }
         delete []temp;
         size = size + obj.size;
         strcpy(str,res.str);
         *res.str='A';
         return *this;
     }
    friend mystr operator + (mystr const &a, mystr const &b);
};

     mystr operator + (mystr const &a, mystr const &b)
     {
         cout<<" here" <<endl;
         int alen = strlen(a.str);
         int blen = strlen(b.str);
         int size = alen+blen+1;
         //char space = " ";
         mystr res(size);
         strcpy(res.str,a.str);
        *(res.str + alen)=' ';
         int i = alen+1;
         int j = 0;
         for(;i<size && j<blen;i++,j++)
         res.str[i] = b.str[j];
         return std::ref(res);
     }
int main()
{
    const char *astr = "hello";
    const char *bstr = "world";
    mystr a = mystr(astr);
    mystr b = mystr(bstr);
   // mystr c = a + b;
    //cout<<c.size<<endl;
    a.display();
    b.display();
    a = a+b;
    a.display();
}