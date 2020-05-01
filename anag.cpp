#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>


void printAnagramsTogether3(char *arr[], int N)
{
  unordered_map < unordered_map<char,int> , vector<char *> > m;
  for(int i = 0;i < N;i++)
  {
     string temp(arr[i]);
     unordered_map<char,int> mt;
     for(int j = 0;j<temp.length();j++)
     {
         mt[temp.at(j)]++;
     }
     m[mt].push_back(arr[i]);
  }
  unordered_map< unordered_map<char,int>, vector<char *> > ::iterator it;
  cout<<endl;
  for(it = m.begin();it != m.end(); it++)
  {
      unordered_map<char,int> tm = it->first;

      for(auto jt = tm.begin();jt != tm.end();jt++)
      {
          cout<<jt->first<<" = "<<jt->second;
      }
      cout<<" : ";
      for(int i = 0;i<it->second.size();i++)
      {
          cout<<it->second[i]<<" , ";

      }
      cout<<endl;
  }

}


string gethash(string t)
{
    vector<int> arr(256,0);
    for(int i = 0; i< t.length();i++)
    {
        arr[t.at(i)]++;
    }
    string res;
    for(int i = 0;i<256;i++)
    {
        
        if(arr[i]!=0)
        {
            //cout<<arr[i];
            int c = arr[i];
            res.push_back((char)i);
            res = res+to_string(c);
        }
    }
    cout<<t<<" ->"<<res<<endl;
    return res;
}

void printAnagramsTogether2(char *arr[], int N)
{
  unordered_map < string , vector<char *> > m;
  for(int i = 0;i < N;i++)
  {
     string temp(arr[i]);
     string hstr = gethash(temp);
     m[hstr].push_back(arr[i]);
  }
  unordered_map< string, vector<char *> > ::iterator it;
  for(it = m.begin();it != m.end(); it++)
  {
      cout<<it->first<<" : ";
      for(int i = 0;i<it->second.size();i++)
      {
          cout<<it->second[i]<<" , ";

      }
      cout<<endl;
  }

}

void printAnagramsTogether(char *arr[], int N)
{
  unordered_map < string, vector<char *> > m;
  for(int i = 0;i < N;i++)
  {
     string temp(arr[i]);
     sort(temp.begin(),temp.end());
     //cout<<arr[i]<<" = "<<temp<<endl;
     m[temp].push_back(arr[i]);
  }
  unordered_map<string,vector<char *> > ::iterator it;
  cout<<endl;
  for(it = m.begin();it != m.end(); it++)
  {
      cout<<it->first<<" : ";
      for(int i = 0;i<it->second.size();i++)
      {
          cout<<it->second[i]<<" , ";

      }
      cout<<endl;
  }

}

int main()
{

    char* wordArr[] = { "cat", "dog", "tac", "god", "act" }; 
    int size = sizeof(wordArr) / sizeof(wordArr[0]); 
    printAnagramsTogether2(wordArr, size); 
    return 0; 
}