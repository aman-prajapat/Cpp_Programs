// doubly link list with all funtions
#include <iostream>
using namespace std;
#include <stdlib.h>

struct node
{
    int var;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void insertFirst(int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->var = val;

    if(start == NULL)
    {
        start = ptr;
        ptr->prev = start;
        ptr->next = start;
    }
    else{
        ptr->next = start;
        ptr->prev =  start->prev ;
        start->prev->next = ptr;
        start->prev = ptr;
        start = ptr;
    } 
}

void insertLast(int val)
 {
     struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->var = val;

    if(start == NULL)
    {
        start = ptr;
        ptr->prev = start;
        ptr->next = start;
    }
    else{
        ptr->next = start;
        ptr->prev =  start->prev ;
        start->prev->next = ptr;
        start->prev = ptr;
    } 
}

void insertMid(int val)
{
    cout<<"Enter index no."<< endl;
    int index;
    cin>>index;

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->var = val;

    int a = 1;
    struct node *temp = start;
    while (a < index)
    {
        temp = temp->next;
        a++;
    }
    
    if (a==0)
    {
        start = ptr;
        ptr->prev = start;
        ptr->next = start;
    }
    else
    {
        ptr->prev = temp->prev;
        ptr->next = temp;
        temp->prev->next = ptr;
        temp->prev = ptr;
    }
}

void delFirst()
{
   start->next->prev = start->prev;
   start->prev->next = start->next;
   start= start->next;
}

void delLast()
{
   start->prev->prev->next= start;
   start->prev = start->prev->prev;
}

void delMid()
{
    cout << "Enter element index want to delete" << endl;
    int index;
    cin >> index;

  int a = 1;
    struct node *temp = start;
    while (a < index)
    {
        temp = temp->next;
        a++;
    }

    if (index == 1)
        start = start->next;
    else if (temp->next == NULL)
        temp->prev->next = NULL;
    else
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
    }
}

void displaylist()
{
    struct node *head = start;
    do
    {
        cout << head->var << " ";
        head = head->next;
    }while (head != start);
    cout << endl;
}

int main()
{
    int val;
    int index, cho;
lable:

    cout << "Enter; \n1  insert from first \n2 last \n3 mid  \n4 delete from first \n5 last \n6 mid \n7 for exit " << endl;
    cin >> cho;

    switch (cho)
    {
    case 1:
        cout << "Enter element" << endl;
        cin >> val;
        insertFirst(val);
        break;

    case 2:
    cout << "Enter element" << endl;
        cin >> val;
        insertLast( val);
        break;

    case 3:
        cout << "Enter element" << endl;
        cin >> val;
        insertMid( val);
        break;
    case 4:
        delFirst();
        break;
    case 5:
        delLast();
        break;
    case 6:
        delMid();
        break;

    case 7:
        exit(0);
    }

    displaylist();
    goto lable;
    return 0;
}