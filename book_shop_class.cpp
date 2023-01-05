#include<iostream>
using namespace std;
#include <fstream>

class book_store{
    int id;
    string book_name;
    string book_author;
    int book_quantity;
    public:
    void search();
    void update();
    void remove();
    void add();
};


void book_store:: search()
{

}

void book_store:: add()
{   
    cout<<"Enter id of Book"<<endl;
     cin>>id;
    cout<<"Enter name of Book"<<endl;
    getline(cin,book_name);
    cout<<"Enter books author name"<<endl;
    getline(cin,book_author);
    cout<<"Enter quantity of Books"<<endl;
    cin>>book_quantity;
}

void book_store:: remove()
{

}

void book_store:: update()
{

}

void showdata(book_store dis)
{
    cout<<dis[0].id<<endl;
}

int main()
{
    int choise;
    book_store shop[20];
    int bookCount = -1;

    cout<<"_________Book store__________"<<endl;
    cout<<"1. Search"<<endl;
    cout<<"2. add"<<endl;
    cout<<"3. remove"<<endl;
    cout<<"4. update"<<endl;
    cout<<"5. exit"<<endl;
    cin>>choise;

    switch(choise){
        
        case 1:
           
        break;

        case 2:
            shop[++bookCount].add();
            showdata(shop);
        break;

        case 3:
            
        break;

        case 4:
            
        break;

        case 5:
            exit(0);
        break;
        default:
        cout<<"Enter a vaild option"<<endl;
        break;
    }





    
    return 0;
}