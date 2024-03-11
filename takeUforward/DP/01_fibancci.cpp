#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long recursion(long long n){
    if(n == 0 || n == 1)return n;
    return recursion(n-1)+recursion(n-2);
}

long long memorization(long long n,vector<long long>&dp){
    if(n == 0)return 0;
    if(dp[n]!=0)return dp[n];
    dp[n] = memorization(n-1,dp)+memorization(n-2,dp);
    return dp[n]; 
}

long long tabul(long long n){
    vector<long long> dp(n+1,0);
    dp[1] = 1;
    for(long long i = 2; i <= n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

long long spaceOpti(long long n){
    if(n < 2)return n;
    long long cur = 0;
    long long prev1 = 0;
    long long prev2 = 1;

    for (long long i = 2; i <= n; i++)
    {
        cur = prev1+prev2;

        prev1 = prev2;
        prev2 = cur;
    }
    
    return prev2;
}
int main()
{
    long long n;
    cin>>n;
    // cout<<recursion(n)<<endl;

    vector<long long> dp(n+1,0);
    dp[1] = 1;
    // memorization(n, dp);
    // cout<<dp[n]<<endl;

    cout<<tabul(n)<<endl;
    cout<<spaceOpti(n)<<endl;
    return 0;
}