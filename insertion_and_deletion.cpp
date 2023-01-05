// INsertti in
#include <iostream>
using namespace std;
 
void insertionInArry(int arr[], int no, int position, int size)
{
    for (int i = size - 1; i >= position - 1; i--)
        arr[i + 1] = arr[i];
    arr[position - 1] = no;
}

void delInArry(int arr[], int position, int size)
{
    for (int i = position - 1; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
}
int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6};
    int no, position;
    int size = 7;
    int s;
    
    cout<<"Enter 1 for insertion and 2 for deletion."<<endl;
    cin>>s;

    switch (s)
    {
    case 1:
        cout << "Enter a No. which you want to insert In Arry \n";
        cin >> no;
        cout << "Enter a position where you want to insert \n";
        cin >> position;
        insertionInArry(arr, no, position, size);
        size++;
        display(arr, size);
        break;
    case 2:
        display(arr, size);
        cout << "\nEnter a position which you want to remove \n";
        cin >> position;
        delInArry(arr, position, size);
        size--;
        display(arr, size);
        break;

    default:
        cout << "Enter a valid input\n";
        break;
    }

    return 0;
}