#include<iostream>
using namespace std;

int main()
{
    string poly;
    cout << "Enter polynomial: " << endl;
    cin>>poly;

    char stack[10],char_selector;
    int top_stack = -1;
    char_selector = poly[0];
   for (int i = 1; char_selector != '\0'; i++)
   {
    if(char_selector == '(' || char_selector == '{' || char_selector == '[')
    {
        top_stack++;
        stack[top_stack]= char_selector;  
    }
    else if(char_selector == ')' || char_selector == '}' || char_selector == ']')
    top_stack--;

    char_selector = poly[i];
   }

   if(top_stack == -1)
   cout<<"All parenthesis are in pair"<<endl;
   else
   cout<<"There are few errors"<<endl;

    return 0;
}