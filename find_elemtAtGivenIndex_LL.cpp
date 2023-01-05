
#include <iostream>
using namespace std;

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

void printmid()
{
    struct node *head = start;

    int index = 0;
    while (head != NULL)
    {
        head = head->next;
        index++;
    }

    index = index/2;

    head=start;
    while (index > 0)
    {
        head = head->next;
        index--;
    }
    cout <<"\n\nThe value at given index\n "<< head->var <<endl;
}

int main()
{
    int val;
    int choices;
lable:
    cout << "Enter : \n1 to insert \n2 for display \n5 to exit" << endl;
    cin >> choices;

    switch (choices)
    {
    case 1:
        cout << "Enter a value : " << endl;
        cin >> val;
        insertFromFirst(val);
        break;
    case 2:
        printmid();
    break;
    case 5:
        exit(0);
    }
   
    goto lable;
    return 0;
}