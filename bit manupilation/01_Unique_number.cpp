//Problem — Unique Number 2N + 1
// Given a list of numbers where every numbers occurs twice except one, find that one number.

#include<iostream>
using namespace std;
int main()
{
    int ele,n;
    cin>>n;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        ans = ans^ele;
    }

    cout<<ans;
    
 return 0;
}