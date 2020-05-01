#include <iostream>
using namespace std;
#include <algorithm>
#define N 4
void displaymat(int arr[][N])
{

    for(int i =0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void transpose(int arr[][N])
{
   for(int i=0;i<N;i++)
   {
       for(int j = i;j<N;j++)
       {
            swap(arr[i][j],arr[j][i]);
       }
   }

}
void reversecol(int arr[][N])
{
   for(int i = 0;i<N;i++)
   {
       int j,k;
       for(j = 0,k=N-1;j<k;j++,k--)
       {
           swap(arr[j][i],arr[k][i]);
       }
   }

}

void rotatemat(int mat[][N])
{
   displaymat(mat); 
   transpose(mat);
   displaymat(mat);
   reversecol(mat);
   displaymat(mat);
}

int main() 
{ 
    // Test Case 1 
    int mat[N][N] = { 
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16} 
    };
   rotatemat(mat);
  // displaymat(mat);
   return 0;
}