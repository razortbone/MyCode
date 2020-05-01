 #include <iostream>
 using namespace std;
 #include <vector>
 #include <algorithm>

 bool compare(int x,int y)
 {
     return (abs(x) < abs(y));
 }

 int findMinSum(vector<int> arr,int n)
 {
    int smin,fmin;
    int smax,fmax;
    smin = fmin = INT_MAX;
    smax = fmax = INT_MIN;

    for(int i = 0;i<n; i++)
    {
       if(arr[i] > 0)
       { 
        if ( arr[i]< fmin)
        {
            smin = fmin;
            fmin = arr[i];
        }
        else if(arr[i]< smin)
            smin = arr[i];
       }
    }
    for(int i = 0;i<n; i++)
    {
        if(arr[i] < 0)
        {
        if ( arr[i]> fmax)
        {
            smax = fmax;
            fmax = arr[i];
        }
        else if(arr[i]> smax)
         {   smax = arr[i];
         }
        }
    }
    cout<<fmin<<" and "<<smin<<endl;
    cout<<fmax<<" and "<<smax<<endl;
    return 0;
 }

 int myfindMinSum(vector<int> arr,int n)
 {
     int x,y,minsum;
     x = y = minsum =  INT_MAX;
     sort(arr.begin(),arr.end(),compare);
     for(int i = 0;i<n-1;i++)
     {
         if (abs(arr[i]+ arr[i+1])<= minsum)
         {
             minsum = abs(arr[i]+ arr[i+1]);
             x = arr[i];
             y = arr[i+1];
         }
     }
     cout<<x<<" and "<<y;
     cout<<endl;
     return 0;
 }

// Driver code 
int main() 
{ 
  
    int arr[] = { 1, 60, -10, 70, -80, 85 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    //sort(arr,arr+n);
    vector<int> mat(arr,arr+n);
    findMinSum(mat, n); 
    return 0; 
    // This code is contributed by ceeyesharish 
}