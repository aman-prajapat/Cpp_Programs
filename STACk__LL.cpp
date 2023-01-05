// _stack using link list 
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next = NULL;
};
 struct node *start = NULL;
 struct node *last = NULL;
void push()
{   
    int num;
    cout << "Enter a number to push" << endl;
    cin>>num;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    ptr->next=NULL;

        if(start == NULL)
        {
            start = ptr;
            last = ptr;
        }
        else{
            last->next = ptr;
            last= ptr;
        }
}

void pop()
{
   if(start == NULL)
       cout << "No element to pop (Under flow)" << endl;
   else if(start->next == NULL && last->next == NULL) 
                start = last = NULL;
   else {
    struct node *temp = start;
    struct node *prev;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    last = prev;
    last->next =NULL;
   }
        
}

void Display()
{
  if(start == NULL)
    cout << "No elements to display (stack empty)" << endl; //stack empty
    else
    {
    struct node *head = start;
    do
    {
        cout << head->data << " ";
        head = head->next;
    }while (head != NULL);
    cout << endl;
    }
}

int main()
{   
    int ch,m;
    lable:

    cout <<"\nenter 1 for push \nEnter 2 for pop \nEnter 0 for exit "<< endl;
    cin>>ch;
     
    switch(ch)
    {
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 0:
        exit(0);
        default:
        cout<<"Enter a vaild optio" << endl;
        break;
    }
 
 Display();
 goto lable;
}
