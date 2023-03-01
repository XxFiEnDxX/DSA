#include<iostream>
using namespace std;

void clearithbits(int &n,int i){
    int mask = ~0;
    mask = mask<<i;
    n = n&mask;
    cout<<n;
}
void clearRangeOfBits(int &n,int i,int j){
    int a = (~0)<<j;
    int b = ~((~0)<<(i-1));
    int mask = a|b;

    n = n&mask;
    cout<<n;
}

int main()
{
    int n;
    int i;
    int j;

    cin>>n;
    cin>>i;
    cin>>j;

    // clearithbits(n,i);
    clearRangeOfBits(n,i,j);

 return 0;
}