#include <iostream>
using namespace std;

int fastPow(int p, int n)
{
    if (n == 0)
    {
        return 1; 
    }

    int smaller_num =  fastPow(p,n/2);
    smaller_num *= smaller_num;
    
    if (n&1)
    {
        return smaller_num*p;
    }
    return smaller_num;
    
}
int main()
{
    int p, x;

    cin >> p>> x;

    cout<<fastPow(p,x);

    return 0;
}