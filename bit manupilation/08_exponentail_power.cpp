#include<iostream>
using namespace std;

int power(int a,int n){
    int ans = 1;
    int last_bit;

    while (n > 0)
    {
        last_bit = n&1;
        if (last_bit)
        {
            ans *= a;
        }
        n = n>>1;
        a *= a;
    }
    return ans;
}

int main()
{
    int a,n;
    cin>>a>>n;

    cout<<power(a,n);
 return 0;
}