#include <iostream>
using namespace std;

struct node
{
    struct node *left;
    int value;
    struct node *right;
};

node *GetNode(int data)
{
    node *newnode = new node();
    newnode->value = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insert(node *root, int data)
{
    if (root == NULL)
        root = GetNode(data);
    else if (data <= root->value)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}


void inOrder(struct node *dis)
{
    if (dis == NULL)
        return;
    inOrder(dis->left);
    cout << dis->value<<"  ";
    inOrder(dis->right);
}

void preOrder(struct node *dis)
{
    if (dis == NULL)
        return;
    cout << dis->value<<"  ";
    preOrder(dis->left);
    preOrder(dis->right);
}

void postOrder(struct node *dis)
{
    if (dis == NULL)
        return;
    postOrder(dis->left);
    postOrder(dis->right);
    cout << dis->value<<"  ";
    
}

int main()
{
    struct node *root = NULL;
    int N;
    int ch;
xyz:
    

    cout <<"\nEnter : \n1 for inOrder \n2 for preOrder \n3 for postOrder \n4 to insert element" << endl;
    cin>>ch;
    switch (ch)
    {
        case 1:
        inOrder(root);
        break;
        case 2:
        preOrder(root);
        break;
        case 3:
        postOrder(root);
        break;
        case 4:
        cout << "\nEnter no. to be inserted" << endl;
    cin >> N;

    root = insert(root, N);
    break;
    }
   
    


    goto xyz;
}