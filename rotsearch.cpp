#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int binsearch(int arr[], int l, int h, int key)
{
   int m = (l+h)/2;
   if (arr[m] == key)
   return m;
   else if(arr[m]> key)
   return binsearch(arr,m+1,h,key);
   else
   {
       return binsearch(arr,l,m-1,key);
   }
   return -1;
}

int main() 
{ 
  
  int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}; 
  int n = sizeof(arr1)/sizeof(arr1[0]); 
  int key = 3; 
  vector<int> tab(arr1,arr1+n);
  for(int i =0;i<tab.size();i++) 
  cout<<tab[i]<<" ";
  cout<<endl; 
 
  cout << "Index of the element is : " ;//<<  
         //  pivotedBinarySearch(arr1, n, key); 
             
  return 0; 
}