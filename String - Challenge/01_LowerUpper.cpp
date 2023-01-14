#include <iostream>
using namespace std;
int main()
{
    char In;
    cin >> In;

    if ('A' <= In && In <= 'Z')
    {
        cout << "UPPERCASE";
    }
    else if ('a' <= In && In <= 'z')
    {
        cout << "lowercase";
    }
    else
    {
        cout << "Invalid";
    }

    return 0;
}