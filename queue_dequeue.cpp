// Queue and dequeue
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

void insertionFunctionDe(int queue[], int *first,int *last,int Max)
{
    cout << "Enter Element to be inserted" << endl;
    int val;
    cin >> val;

   cout << "Enter 1 for front in and 2 for last in" << endl;
   int ch;
   cin >> ch;

   switch(ch)
   {
    case 1:
    if (*first == -1 && *last == -1)
    {
        *first = *first + 1;
        *last = *last + 1;
        queue[*first] = val;
    }
    else if (*last == max)
    {
        cout << "--------Over flow queue--------" << endl;
    }
    else{
        *last = *last + 1; 
        temp = queue[*last];
        while (temp!=0)
        {
            queue[temp+1] = queue[temp];
            temp--;
        }
        queue[0] = val;
    }

     
    break;

    case 2:
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
    break;
    
   }
}

void deletionFunctionDe(int queue[], int *first,int *last)
{

}

void display(int queue[], int first, int last)
{
    for (int i = first; i <= last; i++)
    {
        if (first == -1)
        {
            cout << "Empty queue NO element to display" << endl;
            break;
        }

        cout << queue[i] << " ";
    }
}



int main()
{
    int queue[9];
    int Max = 9;
    int first = -1, last = -1;
    int choice, ch;

label:
    cout << "Enter which queue to choose\n1 for Queue \n2 for dequeue" << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
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

        break;

    case 2:
        cout << "Enter 1 for insertion and 2 for deletion." << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:

            insertionFunctionDe(queue, &first, &last, Max);
            display(queue, first, last);

            break;
        case 2:

            deletionFunctionDe(queue, &first, &last);
            display(queue, first, last);

            break;
        }
        break;
    }

    cout << "\nEnetr 1 for more operation and 0 for exit" << endl;
    int aman;
    cin >> aman;

    if (aman == 1)
        goto label;

    else
        exit(0);

    return 0;
}
