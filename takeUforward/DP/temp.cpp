#include<iostream>

using namespace std;
int main()
{
    int ans = 0;
    int ele;cin>>ele;
    while(ele != -1){
        ans+=ele;
        cin>>ele;
    }
    cout<<ans/60.0<<"hr";
    return 0;
}