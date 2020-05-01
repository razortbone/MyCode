#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


int main()  
{  
    int arr[] = {1, 3, 5, 7, 9, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
  
    // Build segment tree from given array  
    int *st = constructST(arr, n);  
  
    // Print sum of values in array from index 1 to 3  
    cout<<"Sum of values in given range = "<<getSum(st, n, 1, 3)<<endl;  
  
    // Update: set arr[1] = 10 and update corresponding  
    // segment tree nodes  
    updateValue(arr, st, n, 1, 10);  
  
    // Find sum after the value is updated  
    cout<<"Updated sum of values in given range = "
            <<getSum(st, n, 1, 3)<<endl;  
    return 0;  
}