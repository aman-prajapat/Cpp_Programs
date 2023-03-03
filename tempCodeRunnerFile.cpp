#include<iostream>
using namespace std;

class Birthday {
    string name;
    string dob;
    Birthday *next = NULL;
    public:
    Birthday(){
        cin.clear();
        cin.ignore(1000, '\n');
        getline(cin,name);
        getline(cin,dob);
    }
    void assign(Birthday *temp);
};

void Birthday::assign(Birthday *temp){
    next = temp;
}
int main()
{
    Birthday *instant;
    int total_entries = 0;
    int choice;
    cout<<"Enter 1 for more friends entry: "<<endl;
    cin>>choice;

    label:
    if(choice==1){
        if(total_entries == 0){
        instant = new Birthday;
        }
        else{
             Birthday temp;
            instant->assign(&temp);
            total_entries++;

        }
    }
    else{
        cout<<"other";
    }
goto label;

    
    return 0;
}