#include <iostream>
using namespace std;
#define N 9
#include <string>
#include <vector>
#include <algorithm>



bool isSquareSafe(vector<vector<int> > mat, int r, int c, int num)
{
   int n = mat.size();  
   for(int i = 0;i<3;i++)
   {
       for(int j = 0;j<3;j++)
       {
           if(mat[r-(r%3)+i][c-(c%3)+j]==num)
           return false;
       }
   }
   return true;
}

bool isColSafe(vector<vector<int> > mat, int c, int num)
{
   int n = mat.size();  
   for(int i = 0;i<n;i++)
   {
       if(mat[i][c] == num)
          return false;
   }
   return true;
}

bool isRowSafe(vector<vector<int> > mat, int r, int num)
{
   int n = mat.size();  
   for(int i = 0;i<n;i++)
   {
       if(mat[r][i] == num)
          return false;
   }
   return true;
}
bool isSafe(vector<vector<int> > mat, int r, int c, int num)
{
    int n = mat.size();
    if ( r < n && c < n && isRowSafe(mat,r,num) && isColSafe (mat,c,num) &&
           isSquareSafe(mat,r,c,num) && mat[r][c] == 0)
           return true;

    return false;
}

void printGrid(vector<vector<int> > mat)
{
     int n = mat.size();
   for(int i =0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           cout<<mat[i][j]<<" ";
           if ((j%3) == 2)
           cout<<"|"<<" ";
       }
       
       cout<<endl;
       if((i%3)==2)
         cout<<"- - - - - - - - - - - -"<<endl;
   }
}
bool isComplete(vector<vector<int> > mat, int &r, int &c)
{
    int n = mat.size();
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(mat[i][j]==0)
            {
               r = i;
               c = j;
               return false;
            }
        }
    }
    return true;
}
bool SolveSudoku(vector<vector<int> > &mat)
{
  int row = 0;
  int col = 0;
  if (isComplete(mat,row,col))
  return true;  
  //cout<<row<<" "<<col<<" ";
  int n = mat.size();
           
  for(int num = 1;num<=9;num++)
  {
     if (isSafe(mat,row,col,num))
      {
         mat[row][col] = num;
         if(SolveSudoku(mat))
            return true;

         mat[row][col] = 0;
       }
   }
 return false;


}

int main()  
{  
   
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  
    
    vector<vector<int> > mat;
    for(int i = 0;i<N;i++)
    mat.push_back(vector<int>(begin(grid[i]),end(grid[i])));
    printGrid(mat);
    cout<<"Solution :"<<endl;    
    if (SolveSudoku(mat) == true)  
    {   
        printGrid(mat);
    }
    else
        cout << "No solution exists";  
  
    return 0;  
}