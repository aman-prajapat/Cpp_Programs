#include <iostream>
using namespace std;
#define MAX 25

struct book
{
    int id;
    string bname;
    string aname;
    int quantity, price;
};

book shopbook[MAX];
int bookCount = -1;

void add()
{
    if (bookCount < MAX)
    {

        cout << "Enter id of Book" << endl;
        cin >> shopbook[bookCount].id;
        cout << "Enter name of Book" << endl;
        cin >> shopbook[bookCount].bname;

        cout << "Enter books author name" << endl;
        cin >> shopbook[bookCount].aname;

        cout << "Enter quantity of Books" << endl;
        cin >> shopbook[bookCount].quantity;
        cout << "Enter price of Books" << endl;
        cin >> shopbook[bookCount].price;
        cout << "---------Book has been successfully added ----------" << endl;
    }

    else
    {
        // int temp2 = 0;
        // for (int i = 0; i < bookCount; i++)
        // {
        //     if (shopbook[i] == NULL)
        //     {
        //         cout << "Enter id of Book" << endl;
        //         cin >> shopbook[i].id;
        //         cout << "Enter name of Book" << endl;
        //         cin >> shopbook[i].bname;

        //         cout << "Enter books author name" << endl;
        //         cin >> shopbook[i].aname;

        //         cout << "Enter quantity of Books" << endl;
        //         cin >> shopbook[i].quantity;
        //         cout << "Enter price of Books" << endl;
        //         cin >> shopbook[i].price;
        //         temp2++;
        //         break;
        //     }
    cout << "-------No space available--------" << endl;

        }
        

    
}

int search()
{
    int temp;

    cout << "Enter book id to be search" << endl;
    cin >> temp;

    for (int i = 0; i <= bookCount; i++)
    {
        if (shopbook[i].id == temp)
            return i;
    }
    return -1;
}

void display(int index)
{
    cout << "Id of book : " << shopbook[index].id << endl;
    cout << "Name of book : " << shopbook[index].bname << endl;
    cout << "Author Name of book : " << shopbook[index].aname << endl;
    cout << "price of book : " << shopbook[index].price << endl;
    cout << "quantity of book : " << shopbook[index].quantity << endl;
}

void remove()
{
    int temp;

    cout << "Enter book id to be remove" << endl;
    cin >> temp;

    for (int i = 0; i <= bookCount; i++)
    {
        if (shopbook[i].id == temp)
        {
            for (int j = i; j < bookCount ; j++){
                shopbook[j].id = shopbook[j+1].id;
                shopbook[j].bname = shopbook[j+1].bname;
                shopbook[j].aname = shopbook[j+1].aname;
                shopbook[j].price = shopbook[j+1].price;
                shopbook[j].quantity = shopbook[j+1].quantity;
            }
            bookCount--;
           temp == -1;
            break;
        }
    }
    if (temp != -1)
    {
        cout << "No book of such id found" << endl;
    }
}

void update()
{
    int temp;

    cout << "Enter book id to be search" << endl;
    cin >> temp;

    for (int i = 0; i <= bookCount; i++)
    {
        if (shopbook[i].id == temp)
        {

            cout << "Enter quantity of Books" << endl;
            cin >> shopbook[i].quantity;
            cout << "Enter new price of Books" << endl;
            cin >> shopbook[i].price;
            break;
        }
    }
}
int main()
{
    int choise;
lable:
    cout << "_________Book store__________" << endl;
    cout << "1. Search" << endl;
    cout << "2. add" << endl;
    cout << "3. remove" << endl;
    cout << "4. update" << endl;
    cout << "5. exit" << endl;
    cin >> choise;

    switch (choise)
    {

    case 1:
        int resultSearch;
        resultSearch = search();
        if (resultSearch != -1)
            display(resultSearch);
        else
            cout << "No book with that id found" << endl;
        break;

    case 2:
        ++bookCount;
        add();
        break;

    case 3:
        remove();
        break;

    case 4:
        update();
        break;

    case 5:
        exit(0);
        break;
    default:
        cout << "Enter a vaild option" << endl;
        break;
    }

    goto lable;
    return 0;
}