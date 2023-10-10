#include<iostream>
using namespace std;
int main()
{
    // for string = "aaaa" length = 4;
    // int m;
    // cin>>m;
    // m--;
    // int a;
    // int i = 4;
    // int p = 64;
    // string ans = "";
    // while(i--){
    //     a = m/p;
    //     m = m%p;
    //     ans += (a+'a');
    //     p /= 4;
    // }
    // cout<<ans;

    //for string length = n;
    int n,m;
    cin>>n>>m;
    m--;
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        char last = m%n+'a';
        ans = last+ans;
        m /= n;
    }
    cout<<ans<<endl;
    
    return 0;
}