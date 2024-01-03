#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int recursion(int n){
    if(n == 0 || n == 1)return n;
    return recursion(n-1)+recursion(n-2);
}
int memorization(int n,vector<int>&dp){
    if(n == 0)return 0;
    if(dp[n]!=0)return dp[n];
    dp[n] = memorization(n-1,dp)+memorization(n-2,dp);
    return dp[n];
    
}
int tabul(int n){
    vector<int> dp(n+1,0);
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    // cout<<recursion(n)<<endl;

    vector<int> dp(n+1,0);
    dp[1] = 1;
    // memorization(n, dp);
    cout<<dp[n]<<endl;

    cout<<tabul(n)<<endl;
    return 0;
}