#include<iostream>
using namespace std;

bool isOdd(int n){
    return (n&1);
}

int getBit(int n,int i){
    int mask = 1<<i;
    return (n&mask)>0?1:0;
}

void setBit(int &n,int i){
    int mask = 1<<i;
    n = n|mask;
    cout<<n<<endl;
}
void clearBit(int &n,int i){
    int mask = 1<<i;
    mask = ~mask;
    n = n&mask;
    cout<<n<<endl;
}

int main()
{
    int n;
    int i;

    cin>>n;
    cin>>i;

    // cout<<isOdd(n)<<endl;
    // cout<<getBit(n,i)<<endl;
    // setBit(n,i);
    clearBit(n,i);


 return 0;
}