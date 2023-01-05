
#include <iostream>
using namespace std;
#include <stdlib.h>

struct node
{
    int var;
    struct node *next;
};

struct node *start = NULL;
struct node *last = NULL;

void insertFromFirst(int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->var = val;
    ptr->next = NULL;

    if(start == NULL)
     {
         start=ptr;
         last = ptr;
     }
    else{
        last->next = ptr;
        last = ptr;
    } 
}

int count()
{
    int count=0;
    struct node *head = start;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}


int main()
{
    int val,index;
    int choices;
lable:
    cout << "Enter : \n1 to insert \n2 for count \n5 to exit" << endl;
    cin >> choices;

    switch (choices)
    {
    case 1:
        cout << "Enter a value : " << endl;
        cin >> val;
        insertFromFirst(val);
        break;
    case 2:
        cout<<"Total no of nodes are : " << count()<<endl;
        break;
    case 5:
        exit(0);
    }
   
    goto lable;
    return 0;
}