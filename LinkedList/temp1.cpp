#include<iostream>
#include<math.h>
using namespace std;

int powerO(int a,int i){
    if (i==1)
    {
        return a;
    }
    return a*powerO(a,i-1);
}

int main()
{
    cout<<powerO(2,5);
    return 0;
}