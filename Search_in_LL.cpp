
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

int search(int element)
{
    int a =0;
    node *temp = start;
    while (temp != NULL)
    { 
        if (temp->var == element)
        {
            return a;
        }
        else{
            temp = temp->next;
        }
        a++;
    }
}

int main()
{
    int val,element;
    int choices,temp;
lable:
    cout << "Enter : \n1 to insert \n2 for search \n3 to exit" << endl;
    cin >> choices;

    switch (choices)
    {
    case 1:
        cout << "Enter a value : " << endl;
        cin >> val;
        insertFromFirst(val);
        break;
    case 2:
    cout << "Enter a element " << endl;
    cin>>element;
        temp = search(element);
        if (temp == 0){
            cout << "No such element in list" << endl;
        }
        else{
            cout << "elemet fount at index " << temp << endl;
        }
    break;
        case 3:
        exit(0);
    }
   
    goto lable;
    return 0;
}