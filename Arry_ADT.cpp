#include<iostream>
using namespace std;

struct arry{
    int totalSize;
    int usedSize;
    int *ptr;
};

void createArry(struct arry *temp, int size, int usedSize)
{
    temp->totalSize = size;
    temp->usedSize = usedSize;
    temp->ptr = new int[size];
    // temp->ptr = (int*)malloc(size * sizeof(int));
}

void insertionArray(struct arry *temp,int number)
{
    if(temp->totalSize == temp->usedSize)
     cout<<"Arry is full"<<endl;
     else{
    temp->ptr[temp->usedSize] = number;
    temp->usedSize = temp->usedSize + 1;
     }
}

void displayArray(struct arry *temp)
{
    cout<<temp->totalSize<<" "<<temp->usedSize<<endl;

    for(int i=0;i<temp->usedSize;i++)
        cout<<temp->ptr[i]<<" ";
    
    cout<<endl;
}
int main()
{
    struct arry marks;
    int totalSize,usedSize;
    int number;

    cout<<"enter total size and used size "<<endl;
    cin>>totalSize>>usedSize;
    createArry(&marks,totalSize,usedSize);

    lable:
    cout<<"enter number"<<endl;
    cin>>number;
    insertionArray(&marks,number);

    cout<<"Details of Arry"<<endl;
    displayArray(&marks);
    goto lable;

    return 0;
}