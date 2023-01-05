#include <iostream>
using namespace std;
void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
int partition(int arr[],int low,int high)
{
   int pi=arr[high];
   int i=low-1;
   for(int j=low;j<=high-1;j++)
   {
       if(arr[j]<pi)
       {
           i++;
           swap(&arr[i],&arr[j]);
       }

   }
   swap(&arr[i+1],&pi);
   return(i+1);

}
void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int part=partition(arr,low,high);
        quick_sort(arr,low,part-1);
        quick_sort(arr,part+1,high);
    }
}
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;

}
int main()
{
    int arr[]={10,80,30,90,40,50,70};
    int n=sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,n-1);
    cout<<"sorted array:\n";
    display(arr,n);
    return 0;
}