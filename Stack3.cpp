// _stack 
#include <iostream>
using namespace std;

void push(int arry[], int *Fsize , int Choise, int size)
{
    int Choelement;
    if (Choise == 0)
    {
        cout << "Enter a element you want to Push" << endl;
        cin >> Choelement;
        if (*Fsize < size)
        {
            arry[*Fsize] = Choelement;
            *Fsize = *Fsize + 1;
        }
        else{
            cout<<"No space to insert element (Overflow)"<< endl;
        }
    }
}

void pop(int *Fsize, int Choise)
{
    if (Choise == 1)
    {
        if (*Fsize > 0)
            *Fsize = *Fsize - 1;
        else
            cout << "No element to pop (Under flow)" << endl; // underflow
    }
}

void Display(int arry[], int size)
{
    if (size > 0)
    {
        for (int i = 0; i < size; i++)
            cout << arry[i] << " ";
    }
    else
        cout << "No elements to display (stack empty)" << endl; //stack empty
}

int main()
{
    int arry[10] = {1, 2, 3, 4, 5};
    int size = 10;
    int Fsize = 5; // filled size
    int Choise;

   lable:
    cout << "\nif you want to delete last element press 1 \n ____And____ \nif you want to add an element press 0" << endl;
    cin >> Choise;
    if (Choise == 0 || Choise == 1)
    {
        push(arry, &Fsize,  Choise, size);
        pop(&Fsize, Choise);
        Display(arry, Fsize);
    }
    else
    {
        cout << "Enter A valid choise" << endl;
    }
    goto lable;
    return 0;
}
