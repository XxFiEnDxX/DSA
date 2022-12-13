#include <iostream>
using namespace std;

int pow(int p, int x)
{
    if (x == 0)
    {
        return 1;
    }

    return p*pow(p,x-1);
    
}
int main()
{
    int p, x;

    cin >> p>> x;

    cout<<pow(p,x);

    return 0;
}