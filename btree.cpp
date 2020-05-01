#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
    node(int d):data(d){};

};

typedef node Node;
node *newnode(int d)
{
    node *t = new node(d);
    t->data = d;
    t->left = t->right = NULL;
    return t;
}

void pputil(node *t, vector<int> arr)
{
    if (!t) return;
    arr.push_back(t->data);
    if (!t->left && !t->right)
    {
        for(int i = 0;i<arr.size();i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
    pputil(t->left,arr);
    pputil(t->right,arr);
}

bool isSumTree(node *t)
{
   if (!t) return true;
    
   if ( !t->left && !t->right)
        return true;
    if (isSumTree(t->left) && isSumTree(t->right))
    {
        int lval = 0;
        int rval = 0;
        if(!t->left)
        lval = 0;
        else if(!t->left->left && !t->left->right)
        lval = t->left->data;
        else
        lval = 2 * (t->left->data);

        if (!t->right)
        rval = 0;
        else if(!t->right->left && !t->right->right)
        rval = t->right->data;
        else 
        rval = 2 * (t->right->data);

        return (t->data==lval+rval);
    }
    return false;
}

void printPaths(node *root)
{
  vector<int> arr;
  pputil(root,arr);
}
void myprintpath(node *t, int k, vector<int> &parr, int sum)
{
    if(!t) return;
    parr.push_back(t->data);
    sum = sum + t->data;
    cout<<"Sum = "<<sum<<" and k = "<<k<<endl;
   //if(sum == k)
    //{
        if(t->left ==NULL && t->right == NULL)
        {
        for(int i =0;i<parr.size();i++)
        cout<<parr[i]<<" ";
        cout<<endl;
        }
          //sum = sum - parr[parr.size()-1];
    //}
    //parr.pop_back();
    myprintpath(t->left,k,parr,sum);
    myprintpath(t->right,k,parr,sum);
    parr.pop_back();
    //sum = sum - t->data;

    //sum = sum


}

void printKPath(node *root, int k)
{
    if (!root) return;
    vector<int> parr;
    int sum = 0;
    cout<<" Path with sum "<<k<<" in the tree is :"<<endl;
    myprintpath(root,k,parr,sum);
}

int main()  
{  
      
    /* Constructed binary tree is  
                10  
            / \  
            8 2  
        / \ /  
        3 5 2  
    */
   Node *root  = newnode(10); 
    root->left  = newnode(28); 
    root->right = newnode(13); 
  
    root->right->left   = newnode(14); 
    root->right->right  = newnode(15); 
  
    root->right->left->left   = newnode(21); 
    root->right->left->right  = newnode(22); 
    root->right->right->left  = newnode(23); 
    root->right->right->right = newnode(24);
  
    int k = 38; 
    printPaths(root);
    printKPath(root, k); 
      

    //printPaths(root);  
    return 0;  
} 