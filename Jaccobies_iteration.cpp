#include<iostream>
using namespace std;

int main()
{   int n;

    float a[3],b[3],c[3],d[3];
    float x1,y1,z1,x2,y2,z2;
    float x,y,z;
    cout<<"Enter first eq. cofficent \n";
    cin>>a[0]>>b[0]>>c[0]>>d[0];
    cout<<"Enter second eq. cofficent \n";
    cin>>a[1]>>b[1]>>c[1]>>d[1];
    cout<<"Enter third eq. cofficent \n";
    cin>>a[2]>>b[2]>>c[2]>>d[2];
    cout<<"Enter no. of iterations\n";
    cin>>n;

    
    if(a[0] >= (abs(b[0]) + abs(c[0])) && b[1] >= (abs(a[1]) + abs(c[1])) && c[2] >= (abs(a[2]) + abs(b[2])))
    {

        for(int i = 0; i <= n ; i++){ 
            if(i == 0){
                x1 = d[0]/a[0];
                y1 = d[1]/b[1];
                z1 = d[2]/c[2];
                cout<<"Iteration "<<i<<" : "<<x1<<" "<<y1<<" "<<z1<<endl;
            }

            else{
                x2 = (d[0] - (b[0]*y1) - (c[0]*z1))/a[0];
                y2 = (d[1] - (a[1]*x1) - (c[1]*z1))/b[1];

                z2 = (d[2] - (a[2]*x1) - (b[2]*y1))/c[2];
                x1 = x2;
                y1 = y2;
                z1 = z2;
                cout<<"Iteration "<<i<<" : "<<x1<<" "<<y1<<" "<<z1<<endl;
            }
        }
    }
    else{
        cout<<"Jaccobis is not applicable\n";
        abort();
    }

    cout<<"Value of X Y Z are "<<x1<<" "<<y1<<" "<<z1<<endl;

    return 0;
}