// Queue
#include <iostream>
using namespace std;


void insertionFunction(int queue[], int *first, int *last, int max)
{
    cout << "Enter Element to be inserted" << endl;
    int temp;
    cin >> temp;

    if (*first == -1 && *last == -1)
    {
        *first = *first + 1;
        *last = *last + 1;
        queue[*first] = temp;
    }
    else if (*last == max)
    {
        cout << "--------Over flow queue--------" << endl;
    }
    else
    {
        *last = *last + 1;
        queue[*last] = temp;
    }
}

void deletionFunction(int queue[], int *first, int *last)
{
    if (*first == *last && *first != -1)
    {
        *first = *last = -1;
    }
    else if (*first == -1 && *last == -1)
    {
        cout << "------Underflow------- \n There is no element in the queue to remove" << endl;
    }
    else
    {
        *first = *first + 1;
    }
}

void display(int queue[], int first, int last)
{
    for (int i = first; i <= last; i++)
    {
        if (first == -1)
            { cout<<"Empty queue NO element to display"<<endl;
                break;}

        cout << queue[i] << " ";
    }
}

int main()
{
    int queue[9];
    int Max = 9;
    int first = -1 , last = -1;
    int choice;

    label:
    cout << "Enter 1 for insertion and 2 for deletion." << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    
        insertionFunction(queue, &first, &last, Max);
        display(queue, first, last);

        break;
    case 2:
    
        deletionFunction(queue, &first, &last);
        display(queue, first, last);
        
        break;
    }
    
    cout<<"\nEnetr 1 for more operation and 0 for exit"<<endl;
    int aman;
    cin>>aman;

    if(aman == 1)
    goto label;
    
    else
    exit(0);

    return 0;
}
