#include <iostream>
using namespace std;

typedef struct queue
{
    int value;
    struct queue *next;
} VAL;

VAL *start = NULL;
VAL *last = NULL;

void insertInQueue()
{
    int temp;
    cout << "\nEnter value to be inserted" << endl;
    cin >> temp;

    VAL *ptr = (VAL *)malloc(sizeof(VAL));
    ptr->value = temp;

    if (start == NULL)
    {
        ptr->next = NULL;
        last = ptr;
        start = ptr;
    }
    else
    {
         ptr->next = NULL;
        last->next = ptr;
        last = ptr;
    }
}

void del()
{

    if (start == NULL)
        cout << "No element to be deletion" << endl;
    else if (last == start)
        start = NULL;
    else
        start = start->next;
}

void display()
{
    VAL *temp = start;
    if (temp == NULL)
        cout << "No element to display" << endl;
    else
    {
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }
}

int main()
{
X:
    cout << "\nEnetr 1 for insertion and  2 for deletion" << endl;
    int ch;
    cin >> ch;

    switch (ch)
    {
    case 1:
        insertInQueue();
        display();
        break;

    case 2:
        del();
        display();
        break;
    }

    goto X;
    return 0;
}