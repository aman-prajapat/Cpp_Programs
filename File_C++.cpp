#include<iostream>
#include<fstream>

using namespace std;

int main()
{   
    string temp ;
    // used to write in file
    ofstream out("tet.txt"); 
    getline(cin,temp);
    out<<temp;
    out.close();

    /*or
    ofstream out;
    out.("tet.txt");
    */

   //used to in 
    // ifstream in("tet.txt"); 
    // in>>temp;
    // cout<<temp<<endl;

    // getline(in, temp);
    // cout<<temp<<endl;  
    // in.close();  

    /*
    while(in.eof()== 0)
    {
        getline(in,temp);
        cout<<temp;
    }
    */
    return 0;
}