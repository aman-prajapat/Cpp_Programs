#include <iostream>
using namespace std;
#include <iomanip>
class Birthday
{
    string name;
    int date, month, year;
    Birthday *next = NULL;

public:
    Birthday()
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter Name of Family member or Friend: \n";
        getline(cin, name);

        cout << "Enter Date of birth of that person (Formate = -date- -month- -year-): \n";
        cin >> date >> month >> year;
    }
    void assign(Birthday *temp);
    void display();
    void DisplayByMonth(int);
};

void Birthday::assign(Birthday *temp)
{
    next = temp;
}

void Birthday::DisplayByMonth(int months)
{
    int counter = 0;
    Birthday *temp = this;
    cout << "List of all DOB entries" << endl;
            cout<<setw(17)<<"Name"<<setw(20)<<"DOB"<<endl;
    do
    {
        if(temp == NULL){
            cout<<"No Birthday Records Found"<<endl;
            break;
        }
        if (temp->month == months)
        {
            cout << setw(20)<<temp->name;
            cout << setw(10)<<temp->date << "/" << temp->month << "/" << temp->year << "\n";
            counter++;
        }
        temp = temp->next;
        if(temp == NULL ){
            if(counter  == 0)
            cout<<"No Birthday Records Found"<<endl;
            else
            cout<<"Total Record found are: "<<counter<<endl;
        }
    } while (temp != NULL);
    cout<<"***********************************************************\n";
}
void Birthday::display()
{
    Birthday *temp = this;
    cout << "List of all DOB entries" << endl;
        cout<<setw(15)<<"Name"<<setw(18)<<"DOB"<<endl;
    do
    {
        cout << setw(20)<<temp->name;
        cout << setw(10)<<temp->date << "/" << temp->month << "/" << temp->year << "\n";
        temp = temp->next;
    } while (temp != NULL);
    cout<<"***********************************************************\n";
}
int main()
{
    Birthday *instant;
    Birthday *last;
    int total_entries = 0;
    int choice;
label:

    cout << "----------------------------------------------" << endl;
    cout << "         -------BIRTHDAY LIST---------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Enter 1 for more friends entry: \nEnter 2 to show all data: 
     \nEnter 3 to get Birthday list accourding to Months :
     \nEnter 4 for exit" << endl;
    cout << "----------------------------------------------" << endl;
    cin >> choice;

    if (choice == 1)
    {
        if (total_entries == 0)
        {
            instant = new Birthday;
            last = instant;
            total_entries++;
        }
        else
        {
            Birthday temp;
            last->assign(&temp);
            last = &temp;
            total_entries++;
        }
    }
    else if (choice == 2)
    {
        instant->display();
    }
    else if (choice == 3)
    {
        cout<< "Enter which Month data do you want (select from 1-12): " << endl;
        cin >> choice;

        instant->DisplayByMonth(choice);
    }
    else
    {
        cout << "Your Data hass been recorded and saved \n";
        abrot();
    }
    goto label;

    return 0;
}