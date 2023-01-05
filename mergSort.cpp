#include<iostream>
using namespace std;

void printArray(int array[],int size){
    for(int i = 0; i < size ; i++)
        cout<<array[i]<<" ";
        cout<<endl;
}

void merSort(int arr[],int low,int mid,int high){

    int i,j,k,temp[100];
    i = low;
    j = mid + 1;
    k=low;
    
    while (i <= mid && j<=high)
    {
        if (arr[i] < arr[j])
        {
            temp[k]=arr[i];
            i++; 
            k++;
        }
        else
        {
            temp[k]=arr[j];
            j++; 
            k++;
        }
    }    

    while (i<=mid)
    {
        temp[k]=arr[i];
        i++; 
        k++;
    } 
    while (j<=high)
    {
        temp[k]=arr[j];
        j++; 
        k++;
    }
   
    for (int i = low; i <= high; i++)
        arr[i]=temp[i];
       
}
void mergSortDivide(int arr[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;
        mergSortDivide(arr,low,mid);
        mergSortDivide(arr,mid+1,high);
        merSort(arr,low,mid,high);
    }
}
int main()
{
    int arr[10] = {1,8,5,6,7,2,0,3,4,9};
    int high = 10;

    printArray(arr,high);
    mergSortDivide(arr,0,high-1);
    printArray(arr,high);
    return 0;
}