#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int ans = 0;
    while (n != 0)
    {
        if(n&1){
            ans++;
        }
        n = n>>1;
    }
    return ans;
}

int fastCountSetBits(int n){ 
    int ans = 0;
    while (n!=0)
    {
        n = n&(n-1);
        ans++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << fastCountSetBits(n)<<endl;

    cout<< __builtin_popcount(n)<<endl; //built-in function
    return 0;
}