// CircularQueue
#include <iostream>
using namespace std;

int first = -1 , last = -1;

void insertionFunction(int queue[],int max)
{
    cout << "Enter Element to be inserted" << endl;
    int temp;
    cin >> temp;

    if (first == -1 && last == -1)
    {
        first++;
        last++;
        queue[first] = temp;
    }
    else if ((last + 1)%max != first && last == (max - 1))
    {
        last++;
        int x = last%max ;
        queue[x] = temp;
    }
    else if((last + 1)%max == first)
        cout << "------overflow------" << endl;
    else
    {
        last++;
        int x = last%max ;
         queue[x] = temp;
    }
}

void deletionFunction(int queue[],int max)
{
    if (first == last && first != -1)
        first = last = -1;
    else if (first == -1 && last == -1)
        cout << "------Underflow-------" << endl;
    else
        first++;
}

void display(int queue[],int max)
{
    for (int i = first; i <= last; i++)
    {
        if (first == -1)  
        {
            cout<<"No element in queue to display"<< endl;
            break;
        } 

        int x = i % max;
        cout << queue[x] << " ";
    }
}

int main()
{
    int queue[3];
    int Max = 3;
    int choice;

    xyz:
    cout << "\nEnter 1 for insertion and 2 for deletion." << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        insertionFunction(queue, Max);
        display(queue,Max);
        break;
    case 2:
        deletionFunction(queue,Max);
        display(queue,Max);
        break;
    }
    
    cout<<"\nEnetr 1 for more operation and 0 for exit"<<endl;
    int aman;
    cin>>aman;
    if(aman == 1)
    goto xyz;
    else
    exit(0);
    return 0;
}
