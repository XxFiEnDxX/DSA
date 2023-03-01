#include<iostream>
using namespace std;

void clearRangeBits(int &n,int i,int j){
    int a =  (~0)<<5;
    int b = ~((~0)<<(i-1));
    int mask = a|b;

    n = n&mask;
}

int main()
{
    int n,i,j,m;
    cin>>n>>i>>j>>m;

    clearRangeBits(n,i,j);

    m = m<<(i-1);

    int ans = n|m;

    cout<<ans;

 return 0;
}