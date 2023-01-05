// Maximum and second maximum values
#include<iostream>
using namespace std;

int max_no(int arr[],int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if(arr[i]>max)
            max= arr[i]; 
    }
    return max;
}

int SecondMax(int arr[],int size,int max)
{   int secMax = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > secMax  && arr[i] != max){
            secMax = arr[i];
        }
    }
    return secMax;
}

void ArryIn(int arr[],int size){
    cout<< "Enter 10 element in the array"<< endl;
    for(int i = 0; i < size; i++)
        cin>>arr[i];
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9};
    int size= sizeof(arr)/sizeof(int);

    ArryIn(arr,size);
    int max_value = max_no(arr,size);
    int sm = SecondMax(arr,size,max_value);

    cout<<"max no is "<<max_value<<endl;
    cout<<"second max no is "<<SecondMax(arr,size,max_value)<<endl;

    return 0;
}