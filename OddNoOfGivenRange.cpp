#include <iostream>
using namespace std;

void checkForPrime(int start, int end)
{
    if (start > 2)
    {
        for (int i = start; i <= end; i++)
        {
            if (i % 2 == 1)
                cout << i << " " << endl;
        }
    }
    else
    {

        if (start < 2)
        {
            cout << "1 2 ";
            start = 3;
        }
        else if (start == 2)
        {
            cout << "2 ";
            start = 3;
        }

        for (int i = start; i < end; i++)
        {
            if (i % 2 == 1)
                cout << i << " ";
        }
    }
}
int main()
{
    int start, end;

    cout << "Enter a range " << endl;
    cin >> start >> end;

    checkForPrime(start, end);
}