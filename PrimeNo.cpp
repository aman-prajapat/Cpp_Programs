#include<iostream>
using namespace std;

int primeNo(int x ,int y)
{
    for (int i = x; i < y; i++)
    {
        int v = 0;

        for (int j = 2; j < i ; j++)
        {  
            if(i%j == 0)
            {
                v++;
                break;  
            }
        }

         if(v == 0)
          cout<<i<<" ";
    }
}
int main()
{
    int a,b;

    cout<<"  -------------------  "<<endl;
    cin>>a>>b;
    primeNo(a,b); 
}