#include<iostream>
using namespace std;
#include<limits>

void printArray(int array[],int size){
    for(int i = 0; i < size ; i++)
        cout<<array[i]<<" ";
        cout<<endl;
}

int maxElement(int arr[],int size)
{
    int max = INT_MIN;
    for (int i = 0; i <= size; i++)
    {
        if (max<arr[i])
        max=arr[i];
    }
    return max;
}

void countSort(int arr[],int size)
{
    int max = maxElement(arr,size) + 1;
    int *count = new int[maxElement(arr,size)*sizeof(int) + 1] ;

    int i , j;
    for ( i = 0; i <= maxElement(arr,size)  ; i++)
       count[i] = 0;

    for ( j = 0; j < size; j++)
        count[arr[j]] = count[arr[j]] +1;
    
   j = i =0;

   while (i< max)
   {
        if(count[i]>0)
       {
        arr[j] = i;
        count[i] = count[i] -1;
        j++;
       }
       else
       i++;
   }  
}
int main()
{
    int arr[10] = {1,8,5,7,7,2,0,3,4,9};
    int high = 10;

    printArray(arr,high);
    countSort(arr,high-1);
    printArray(arr,high);
    return 0;
    
}