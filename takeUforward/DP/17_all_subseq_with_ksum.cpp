#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007

int sol(int n, vector<int> &arr, int k,vector<vector<int>>&dp){
    // if(k == 0){
    //     // cnt++;
    //     return 1;
    // }
    // if(n < 0)return 0;

    if(n == 0){
        if(k == 0 && arr[0] == 0)return 2;
        if(k == 0 || arr[0] == k)return 1;
        return 0;
    }

    if(dp[n][k] != -1)return dp[n][k];
    int ans = (k >= arr[n])?sol(n-1,arr,k-arr[n],dp):0;
    ans += sol(n-1,arr,k,dp);

    return dp[n][k] = ans % Mod;
}
int main()
{
    int n;cin>>n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)cin>>arr[i];
    int t;cin>>t;

    // memorization
    vector<vector<int>> dp(n,vector<int>(t+1,-1));
    cout<<sol(n-1,arr,t,dp);

    // tabulization
    // vector<vector<bool>> dp(n,vector<bool>(t+1,0));
    // for(int i = 0; i < n; i++){
    //     dp[i][0] = 1;
    // }
    // if(arr[0] <= t)dp[0][arr[0]] = 1;

    // for(int i = 1; i < n; i++){
    //     for(int k = 1; k <= t; k++){
    //         bool nonTake = dp[i-1][k];
    //         bool take = 0;
    //         if(arr[i] <= k)take = dp[i-1][k-arr[i]];

    //         dp[i][k] = (take | nonTake);
    //     }
    // }
    // cout<<dp[n-1][t];
    return 0;
}