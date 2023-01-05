// Link list with all funtions
#include <iostream>
using namespace std;
#include <stdlib.h>

struct node
{
    int var;
    struct node *next;
};

struct node *start = NULL;

void InsertFromLast(int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->var = val;
    ptr->next = NULL;
    int a = 1;
    struct node *temp = start;
    do
    {
        if (temp == NULL)
        {
            start = ptr;
            break;
        }
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = ptr;
    } while (a == 0);
}

void insertFromFirst(int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->var = val;
    ptr->next = start;
    start = ptr;
}

void insertAtbetween(int val, int index)
{
    int a = 1;
    struct node *temp = start;

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->var = val;

    while (a < index - 1)
    {
        temp = temp->next;
        a++;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}

void del(int index)
{

    int a = 1;
    struct node *temp = start;
    struct node *prev;

    while (a < index)
    {
        prev = temp;
        temp = temp->next;
        if (temp == NULL && a < index)
        {
            a = -1;
            break;
        }
        a++;
    }
    if (start == NULL)
        cout << "No element found" << endl;
    else if (a == -1)
        cout << "No such index found" << endl;
    else if (a == 1)
        start = temp->next;
    else if (temp->next == NULL)
        prev->next = NULL;
    else
        prev->next = temp->next;
}

void displaylist()
{
    struct node *head = start;
    while (head != NULL)
    {
        cout << head->var << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int val;
    int choices;
lable:
    cout << "Enter : \n 1 to insert from start \n 2 to insert at last \n 3 to instert btw start and last \n 4 for deletion \n 5 to exit" << endl;
    cin >> choices;

    switch (choices)
    {
    case 1:
        cout << "Enter a value : " << endl;
        cin >> val;
        insertFromFirst(val);
        break;

    case 2:
        cout << "Enter a value : " << endl;
        cin >> val;

        InsertFromLast(val);
        break;

    case 3:
        int index;
        cout << "Enter a value : " << endl;
        cin >> val;

        cout << "INdex" << endl;
        cin >> index;

        insertAtbetween(val, index);
        break;
    case 4:
        cout << "INdex" << endl;
        cin >> index;
        del(index);
        break;

    case 5:
        exit(0);
    }

    displaylist();
    goto lable;
    return 0;
}