#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
int findSubsequenceCount(string S, string T)
{
    int m = S.length();
    int n = T.length();
    if (n == 0) return 1;
    if (m == 0) return 0;
    vector<vector<int> > tab(n+1,(vector<int>(m+1,0)));
    for(int i = 1;i <= n;i++)
     tab[i][0] = 0;
    for(int i = 0;i <= m;i++)
     tab[0][i] = 1;
     for(int i = 1;i <= n;i++)
     {
         for(int j = 1;j <= m;j++)
         {
            if (T[i-1] != S[j-1])
              tab[i][j] = tab[i][j-1];
            else
              tab[i][j] = tab[i-1][j-1]+tab[i][j-1];
         }

     }
     return tab[n][m];
}

int main() 
{ 
    string T = "ge"; 
    string S = "geeksforgeeks"; 
    cout << findSubsequenceCount(S, T) << endl; 
    return 0; 
} 