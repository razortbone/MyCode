#include <iostream>
using namespace std;
#include <unordered_map>
#include <list>
struct Node
{
    bool isLeaf;
    unordered_map<char, Node *> map;
};
typedef struct Node node;

node *getnode()
{
    node *temp = new node;
    temp->isLeaf = false;
    
    return temp;
}

int findindex(char ch)
{
    if (isupper(ch))
    return (ch-'A');
    else if(islower(ch))
    return (26+ch-'a');
    else if(isdigit(ch))
    return (52+ch-'0');

    return -1;
}

void insert (node *& root, string str)
{
    //if (root == NULL)
    //root = getnode();

    node *t = root;
    for(int i = 0;i<str.length();i++)
    {
        //int ind = findindex(str.at(i));
        char ch = str.at(i);
        cout<<ch<<" : ";
       
        if(t->map.find(ch)== t->map.end())
        {
            cout<<ch<<" not found"<<endl;
            t->map[ch] = getnode();
        }
        cout<<t->map.size()<<" "<<" ch = "<<ch<<endl;
        t = t->map[ch];
    }
    cout<<root->map.size()<<" "<<endl;
    t->isLeaf = true;

}
int count(node *t, char &ch)
{
    unordered_map< char, node * >  ::iterator it;
    cout<<t->map.size()<<" : ";
    if (t->map.size()==1)
    {
        for ( it = t->map.begin();it != t->map.end();it++)
            ch = it->first;
    }
    return t->map.size();
}

string commonPrefix(Node *&root,string arr[],int n)
{
    
    for(int i = 0;i<n;i++)
        insert(root,arr[i]);
      cout<<" mcP : "<<root->map.size()<<endl; 
    char ch;
    string str;
    node *t = root;
    while (count(t,ch) == 1 && !t->isLeaf)
    {
        str.push_back(ch);
        t = t->map[ch];
    }

    return str;
}
int main() 
{ 
    Node *root = getnode();
    string arr[] = {"geeksforgeeks", "geeks", 
                    "geek", "geezer"}; 
    int n = sizeof (arr) / sizeof (arr[0]); 
      
      cout<<" cP : "<<root->map.size()<<endl; 
    string ans = commonPrefix(root,arr, n); 
  
    if (ans.length()) 
        cout << "The longest common prefix is "
             << ans; 
    else
        cout << "There is no common prefix"; 

    cout<<endl<<root->map.size()<<endl;    
    return (0); 
}