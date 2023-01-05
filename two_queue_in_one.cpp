// Two queue in one arry
#include <iostream>
using namespace std;

void insertionFunction(int queue[], int *first, int *last, int max, int sec)
{
    cout << "Enter Element to be inserted" << endl;
    int temp;
    cin >> temp;

    if (*first == -1 && *last == -1)
    {
        *first = *first + 1 + sec;
        *last = *last + 1 + sec;
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
        cout << "------Underflow------- \n " << endl;
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
            break;

        cout << queue[i] << " ";
    }
}

int main()
{
    int queue[9];
    int Max = 9;
    int max1 = 4;
    int secStart = 5;

    int first = -1, last = -1;
    int first1 = -1, last1 = -1;

    int choice;

label:

    cout << "Enter with which queue you want to work 1 or 2: " << endl;
    int tem;
    cin >> tem;

    switch (tem)
    {
    case 1:
        cout << "Enter 1 for insertion and 2 for deletion." << endl;
        cin >> choice;

        switch (choice)
        {

        case 1:

            insertionFunction(queue, &first, &last, max1, 0);
            display(queue, first, last);

            break;
        case 2:

            deletionFunction(queue, &first, &last);
            display(queue, first, last);

            break;
        }
        break;

    case 2:
        cout << "------Enter 1 for insertion and 2 for deletion------" << endl;
        cin >> choice;

        switch (choice)
        {

        case 1:

            insertionFunction(queue, &first1, &last1, Max, secStart);
            display(queue, first1, last1);

            break;
        case 2:

            deletionFunction(queue, &first1, &last1);
            display(queue, first1, last1);

            break;
        }
        break;
    }

    cout<<"\n-----Enetr 1 for more operation and 0 for exit------"<<endl;
    int temp3;
    cin>>temp3;

    if(temp3 == 1)
    goto label;

    else
    exit(0);

    return 0;
}
