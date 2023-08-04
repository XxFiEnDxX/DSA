#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n = 10;
    for (int i = n/2; i <= n; i++)
    {
        for (int j = 2; j <= n; j=j*2)
        {
            cout<<i<<" "<<j<<endl;
        }
        
    }
    
    return 0;
}