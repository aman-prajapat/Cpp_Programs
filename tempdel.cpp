#include <iostream>
using namespace std;
#include <stdlib.h>

struct node
{
    int var;
    struct node *next;
};


struct node *start = (struct node *)malloc(sizeof(struct node));

void deletelist( int n)
{
    struct node *temp = start;
    struct node * previous;
    int count = 1;
    while (count <n)
    {
        
        count++;
        previous = temp;
        temp=temp->next;
    }

    if(n==1)
    {
        // struct node *temp2=start;
        start=start->next;      
    }
    else
    {
        previous->next=temp->next;
        free(temp);
    }
}

void InsertFromLast(struct node *start, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->var = val;

    struct node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = ptr;
    ptr->next = NULL;
}

void displaylist(struct node *head)
{
    while (head != NULL)
    {
        cout << head->var << " ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    int val;
    int a = 0,n;
    
    lable:
    
    int ch;
    cout<<"Enter 1 for insertion, 2 for deletion"<<endl;
    cin>>n;

    switch(n){
        case 1:
            cout << "Enter a value : " << endl;
            cin >> val;
            
            if (a == 0)
            {
                start->var = val;
                start->next = NULL;
                a++;
            }
            else
                InsertFromLast(start, val);

            displaylist(start);
            break;

        case 2:
            int seq;
            cout << "Enter del value sequence no." << endl;
            cin>>seq;
            deletelist( seq);
            
            displaylist(start);
            break;

    }

    goto lable;
    
    return 0;
}