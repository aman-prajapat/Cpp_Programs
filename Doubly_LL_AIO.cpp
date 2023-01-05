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
int tem = 1;
void insertion(int val, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->var = val;

    int a = 2;
    struct node *temp = start;
    while (a < index)
    {
        temp = temp->next;
        a++;
    }

    if (tem == 1)
    {
        ptr->prev = NULL;
        ptr->next = NULL;
        start = ptr;
        tem++;
    }
    else
    {

        if (index == 1)
        {
            ptr->next = start;
            start->prev = ptr;
            ptr->prev = NULL;
            start = ptr;
        }
        else if (temp->next == NULL)
        {
            ptr->next = NULL;
            ptr->prev = temp;
            temp->next = ptr;
        }
        else
        {
            ptr->next = temp->next;
            temp->next->prev = ptr;
            temp->next = ptr;
            ptr->prev = temp;
        }
    }
}

void del(int index)
{
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
    int index, cho;
lable:

    cout << "Enter 1 for insertion , 2 for deletion and 3 to exit" << endl;
    cin >> cho;

    switch (cho)
    {
    case 1:
        cout << "Enter element" << endl;
        cin >> val;

        cout << "Sequnce number where it placed" << endl;
        cin >> index;

        insertion(val, index);
        break;

    case 2:
        int delindex;

        cout << "Enter element index want to delete" << endl;
        cin >> delindex;

        del(delindex);
        break;

    case 3:
        exit(0);
    }

    displaylist();
    goto lable;
    return 0;
}