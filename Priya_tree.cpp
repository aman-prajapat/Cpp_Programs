#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};


struct node * insert(struct node *r,int n)
{
    if(r==NULL)
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->left=NULL;
        temp->right=NULL;
        temp->data=n;
        return temp;
    }
    else if(n<r->data)
    {
        r->left=insert(r->left,n);
    }
    else if(n>r->data)
    {
        r->right=insert(r->right,n);
    }
  
}
void inorder(struct node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
}
int main()
{
    struct node *p=NULL;
    
    p=insert(p,2);
    struct node *first=p;
    p=insert(p,3);
    p=insert(p,1);
    p=insert(p,5);
    p=insert(p,4);
    inorder(first);
}