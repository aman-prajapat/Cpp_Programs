#include <iostream>
using namespace std;
#include <stdlib.h>

struct poly
{
    int power;
    int cofficent;
    struct poly *next;
};

struct poly *firstP = NULL;
struct poly *last;

void insert1()
{
    int pow;
    int cof;
    cout << "\ninsert power and cofficent" << endl;
    cin >> pow >> cof;

    struct poly *ptr = (struct poly *)malloc(sizeof(struct poly));

    ptr->power = pow;
    ptr->cofficent = cof;
    ptr->next = NULL;

    if (firstP == NULL)
    {
        firstP = ptr;
        last = ptr;
    }
    else
    {
        last->next = ptr;
        last = ptr;
    }
}

void display()
{
    int a=0;
    struct poly *temp = firstP;
    while (temp != NULL)
    {
        if(a>=1)
        cout << " + ";

        cout << temp->cofficent << "X^" << temp->power ;
        temp = temp->next;
        a++;
    }
}

int main()
{

    int degree;
    cout << "degree: " << endl;
    cin >> degree;
    while (degree >= 0)
    {
        insert1();
        degree--;
    }
    display();

    return 0;
}