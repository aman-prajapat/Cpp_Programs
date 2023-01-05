#include <iostream>
#include <string.h>
using namespace std;

void mainWork(char A[], char Exp[], int len)
{
    char stack[10];
    int j = 0, k = 0, m = 0;

    for (int i = 0; i < len; i++)
    {
        if (A[i] == '*' || A[i] == '-' || A[i] == '+' || A[i] == '/' || A[i] == '(')
        {
            stack[j] = A[i];
            j++;

            while (stack[j-1] == stack[j -2] || stack[j-1] == '*' && stack[j-2] == '/' || stack[j-1] == '+' && stack[j-2] == '-' 
            ||stack[j-1] == '/' && stack[j-2] == '*' || stack[j-1] == '+' && stack[j-2] == '/'
            || stack[j-1] == '+' && stack[j-2] == '*'|| stack[j-1] == '-' && stack[j-2] == '+' 
            ||stack[j-1] == '-' && stack[j-2] == '/' ||stack[j-1] == '-' && stack[j-2] == '*' 
            ){
                
            

            if (stack[j-1] == '*' && stack[j-2] == '/')
            {
                Exp[k] = stack[j-2];
                k++;
                j--;
                stack[j-1] = '*';
            }
            else if (stack[j-1] == '*' && stack[j-2] == '*')
            {
                Exp[k] = stack[j-2];
                k++;
                j--;
                stack[j-1] = '*';
            }
            else if (stack[j-1] == '/' && stack[j-2] == '*')
            {
                Exp[k] = stack[j-2];
                k++;
                j--;
                stack[j-1] = '/';
            }
            else if (stack[j-1] == '/' && stack[j-2] == '/')
            {
                Exp[k] = stack[j-2];
                k++;
                j--;
                stack[j-1] = '/';
            }
            else if (stack[j-1] == '+' && stack[j-2] == '+')
            {
                Exp[k] = stack[j-2];
                k++;
                j--;
                stack[j-1] = '+';
            }
            else if (stack[j-1] == '+' && stack[j-2] == '-')
            {
                Exp[k] = stack[j-2];
                k++;
                j--;
                stack[j-1] = '+';
            }
            else if (stack[j-1] == '+' && stack[j-2] == '/')
            {
                Exp[k] = stack[j-2];
                k++;
                j--;

                stack[j-1] = '+';
            }
            else if (stack[j-1] == '+' && stack[j-2] == '*')
            {
                Exp[k] = stack[j-2];
                k++;
                j--;
                stack[j-1] = '+';
            }
            else if (stack[j-1] == '-' && stack[j-2] == '-')
            {
                Exp[k] = stack[j-2];
                k++;
                j--;
                stack[j-1] = '-';
            }
            else if (stack[j-1] == '-' && stack[j-2] == '+')
            {
                Exp[k] = stack[j-2];
                k++;
                j--;
                stack[j-1] = '-';
            }
            else if (stack[j-1] == '-' && stack[j-2] == '/')
            {
                Exp[k] = stack[j-2];
                k++;
                j--;
                stack[j-1] = '-';
            }
            else if (stack[j-1] == '-' && stack[j-2] == '*')
            {
                Exp[k] = stack[j-2];
                k++;
                j--;
                stack[j-1] = '-';
            }
            }
            
        }
        else if(A[i] == ' ')
        continue;

        else if (A[i] == ')')
        {
            int z = j;
            z--;
            while (stack[z] != '(')
            {
                if(stack[z] == ')')
                break;
               Exp[k] = stack[z];
                k++;
                j--;
                z--;
            }
        }
        else
        {
            Exp[k] = A[i];
            k++;
        }
        m = j;
    }

    for (int w = m-1; w >= 0; w--)
    {
        Exp[k] = stack[w];
        k++;
    }
}

void print(char Exp[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if(Exp[i]!='(')
        cout << Exp[i];
    }
}

int main()
{
    char a[40] = "a+(b*c+(d/e)*g)*h)";
    char Exp[30];

    mainWork(a, Exp, strlen(a));
    int length = strlen(Exp);
    print(Exp, length);

    return 0;
}