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
struct poly *secondP = NULL;
struct poly *last;
struct poly *add = NULL;

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
        //  cout << firstP->cofficent<<" X "<<firstP->power<<" + ";
    }
    else
    {
        last->next = ptr;
        last = ptr;
        // cout << firstP->cofficent<<" X "<<firstP->power<<" + ";
    }
}

void insert2()
{
    int pow;
    int cof;
    cout << "\ninsert power and cofficent" << endl;
    cin >> pow >> cof;

    struct poly *ptr = (struct poly *)malloc(sizeof(struct poly));

    ptr->power = pow;
    ptr->cofficent = cof;
    ptr->next = NULL;

    if (secondP == NULL)
    {

        secondP = ptr;
        last = ptr;
        //  cout << secondP->cofficent<<" X "<<secondP->power<<" + ";
    }
    else
    {
        last->next = ptr;
        last = ptr;
        // cout << secondP->cofficent<<" X "<<secondP->power<<" + ";
    }
}

void addition()
{
    struct poly *temp = firstP;
    struct poly *temp2 = secondP;

    while (temp != NULL && temp2 != NULL)
    {
        if (add == NULL)
        {
            struct poly *ptr = (struct poly *)malloc(sizeof(struct poly));
            struct poly *temp3 = secondP;
            while (temp->cofficent != temp3->cofficent)
            {
                temp3 = temp3->next;
            }

            ptr->cofficent = temp->cofficent + temp3->cofficent;
            ptr->power = temp->power;
            ptr->next = NULL;
            last = ptr;
            add = ptr;
            temp = temp->next;
            temp2 = temp2->next;
        }
        else
        {
            struct poly *ptr = (struct poly *)malloc(sizeof(struct poly));
            struct poly *temp3 = secondP;
            while (temp->cofficent != temp3->cofficent)
            {
                temp3 = temp3->next;
            }

            ptr->cofficent = temp->cofficent + temp3->cofficent;
            ptr->power = temp->power;
            ptr->next = NULL;
            last->next = ptr;
            last = ptr;
            temp = temp->next;
            temp2 = temp2->next;
        }
    }

    // while (temp != NULL && temp2!=NULL)
    // {
    //     if(add == NULL)
    //     {
    //         if(temp->cofficent == temp2->cofficent)
    //     {
    //         struct poly *ptr = (struct poly *)malloc(sizeof(struct poly));

    //         ptr->cofficent = temp->cofficent + temp2->cofficent;
    //         ptr->power = temp->power;
    //         ptr->next = NULL;
    //         last=ptr;
    //         add= ptr;
    //         temp=temp->next;
    //         temp2=temp2->next;
    //     }
    //     else if(temp->cofficent < temp2->cofficent)
    //     {

    //     }

    //     }
    // }
}

void display()
{
    struct poly *temp = firstP;

    while (temp != NULL)
    {
        cout << temp->cofficent << " X " << temp->power << " + ";
        temp = temp->next;
    }
}

void display2()
{
    struct poly *temp = secondP;

    while (temp != NULL)
    {
        cout << temp->cofficent << " X " << temp->power << " + ";
        temp = temp->next;
    }
}

void display3()
{
    struct poly *temp = add;

    while (temp != NULL)
    {
        cout << temp->cofficent << " X " << temp->power << " + ";
        temp = temp->next;
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

    int degre;
    cout << "degree: " << endl;
    cin >> degre;
    while (degre >= 0)
    {
        insert2();
        degre--;
    }
    display2();

    addition();
    display3();

    return 0;
}