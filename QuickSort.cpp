#include<iostream>
using namespace std;

void printArray(int array[],int size){
    for(int i = 0; i < size ; i++)
        cout<<array[i]<<" ";
    
}

int partitions(int arry[],int low ,int high)
{
     int pivote = arry[low];
     int i , j ,temp; 
     i = low+ 1;
     j = high ;

     do{
        while (arry[i]<=pivote)
        {
            i++; 
        }
          
        while (arry[j]>pivote)
        {
            j--;
        }

        if(i<j)
        {
          temp = arry[i];
          arry[i] = arry[j];
          arry[j] = temp;  
        }
        
     }while(i<j);

        temp = arry[low];
          arry[low] = arry[j];
          arry[j] = temp;  

return j;
}

void quickSort(int array[],int low, int high)
{
    int partition;

    if(low<high)
    {
        partition = partitions(array,low,high);
        quickSort(array,low,partition -1);
        quickSort(array,partition + 1,high);
        
    }
}
int main()
{
    int arr[10] = {1,6,3,5,16 ,5 , 48, 18};
    int  size = 8;

    quickSort(arr,0,size-1);
    printArray(arr,size); 
    return 0;
}