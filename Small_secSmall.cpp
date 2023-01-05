// Smallest and second smallest 
#include<iostream>
using namespace std;

int min_no(int arr[],int size)
{
    int Min = arr[0];
    for (int i = 1; i <size ; i++)  // 5 9 3 7 4 4
    {
        if(arr[i] < Min )
            {
                Min = arr[i];
            }
    }
    return Min;
}

int SecondMin(int arr[],int size,int Min)
{   int secMin = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(arr[i] < secMin  && arr[i] != Min ){
            secMin = arr[i];
        }
    }
    return secMin;
}

void ArryIn(int arr[],int size){
    cout<< "Enter 10 element in the array"<< endl;
    for(int i = 0; i < size; i++)
        cin>>arr[i];
}

int main()
{
    int arr[10]; // 1 86 47 5 6 2 69 
    int size= 10; //sizeof(arr)/sizeof(int);

    ArryIn(arr,size);
    int MV= min_no(arr,size);
    int sm = SecondMin(arr,size,MV);

    cout<<"Min no is "<<MV<<endl;
    cout<<"second min no is "<<SecondMin(arr,size,MV)<<endl;

    return 0;
}