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

void search(node *root,int val) {
     if(root->value == val)
         cout<<"Element is found"<<endl;
     
     else if(root->value >= val)
        search(root->left,val);
     
     else if(root->value<=val)
        search(root->right,val);

    else
    cout <<"No element found"<<endl;
}

struct node *inOrderPre(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

node *deletion(node *root , int key){
    struct node* iPre;
    if(root->value == NULL){
    return NULL;
    }
    if(root->right == NULL && root->lest == NULL){
        free(root);
        return NULL;
    }
    
    if (key < root->value)
    {
        root-> left = deletion(root->left, key);
    }
    else if(key > root->value){
        root -> right = deletion(root->right, key);
    }

    else{
        iPre = inOrderPre(root);
        root->value = iPre->value;
        root->left = deletion(root->left,iPre->data);

    }
    return root;
    
}
void display(struct node *dis)
{
    if (dis == NULL)
        return;
    display(dis->left);
    cout << dis->value<<"  ";
    display(dis->right);
}

int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
int main()
{
    struct node *root = NULL;
    int N;
    int sear;
xyz:
    cout << "\nEnter no. to be inserted" << endl;
    cin >> N;

    root = insert(root, N);
    display(root);

    cout << "\nEnter no. to be search" << endl;
    cin >> sear;
    
    if(sear==10)
    search(root,sear);

    goto xyz;
}