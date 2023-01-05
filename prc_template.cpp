#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

template<class A> void add(A a,A b){
    cout<<a+b;
}

template<class A,class B> 
class name{ 
    A r;
    public:
        void add(A e){
            r=e;
            cout<<r;
        }
        void sum(B);
        void r0();
};

template <class A,class B>
void name<A,B>::r0(){
    cout<<"name:";
}

template <class A,class B>
void name<A,B>::sum (B b){
            cout<<b;
        }

template <class A>void add(A a ){
        cout<< sizeof(a);
    }
int main()
{

    // name <int,float>object, obj;

    // obj.add(59.6);
    // object.add(12);
    // object.sum(12.568);

    // add<int>(2.2);

    vector<char> object = {'a','b','d','c','q','v','s','i'};

    object.push_back(10);
    // cout<<object.at(0); 
    sort(object.begin(), object.end());

    int i = 4;
    for(int i = 0;i<object.size();i++)
    cout<<object.at(i)<<endl; 
    
    return 0;
}