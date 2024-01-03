#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int n, int step){
    if(n == 0 || n == 1)return n;
    int ways = 0;
    for(int i = 1; i <= step; i++){
        if(n-i >= 0){
            ways += recursion(n-i,step);
        }
    }
    return ways;
}

int memorization(int n, int step, vector<int>&dp){
    if(n == 0 || n == 1)return n;
    if(dp[n] != 0)return dp[n];
    int ways = 0;
    for(int i = 1; i <= step; i++){
        if(n-i >= 0){
            ways += recursion(n-i,step);
        }
    }
    dp[n] = ways;
    return dp[n];
}

int main()
{
    int n; cin>>n;
    int step; cin>>step;

    cout<<recursion(n,step)<<endl;

    vector<int> dp(n+1,0);
    dp[1] = 1;
    cout<<memorization(n,step,dp)<<endl;
    return 0;
}