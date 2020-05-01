#include <iostream>
using namespace std;

#include <pthread.h>
struct TDATA
{
    long tid;
    string msg;
};
typedef TDATA tdata;  
void *disp(void *t)
{
   long tid;
   void *status;
   tid = (long) t;
   cout<<"\n Thread id is"<<tid;
   pthread_exit(NULL);
}
void *disp1(void *t)
{
   long threadid;
   string mesg;
   tdata *mydata = (tdata *)t;
   threadid =  mydata->tid;
   mesg = mydata->msg;
   cout<<"\n Thread id is: "<<threadid;
   cout<<"\n Message is: "<<mesg<<endl;
   
   pthread_exit(NULL);
}
int main()
{
    int ret = 1;
    void *status;
    pthread_t threads[5];
    tdata data[5];
    for(long i =0;i<5;i++)
    {
       data[i].tid = i;
       data[i].msg = " Message of thread "+to_string(i);
       cout<<"\nmain(): Creating thread "<<i;
       ret = pthread_create(&threads[i],NULL,disp1,(void *)&data[i]);
       if (ret)
       {
         cout<<"\n Error in creatin thread"<<i;
         exit(-1);
       }
    }
    for(int i=4; i>0; i--)
	{
		ret=pthread_join(threads[i], &status);
		if(ret)
		{
			cout<<"Error: unable to join, "<<ret<<"\n";
			exit(-1);
		}
		cout<<"main(): completed thread id: "<<i;
		cout<<"  exiting with status: "<<status<<"\n";
	}
    pthread_exit(NULL);

    return 0;
}
