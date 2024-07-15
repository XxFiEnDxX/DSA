#include<bits/stdc++.h>
using namespace std;
bool sol(int i, int t, int n, vector<int>&arr, vector<vector<int>> &dp){
    if(t == 0)return true;
    if(i == 0)return (arr[i] == t);
    if(dp[i][t] != -1)return dp[i][t];
    bool nonTake = sol(i-1,t,n,arr,dp);
    bool take = false;
    if(t >= arr[i]){
        // t -= arr[i];
        take = sol(i-1,t-arr[i], n, arr, dp);
    }

    return dp[i][t] = take||nonTake;
}
int main()
{
    int n;cin>>n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)cin>>arr[i];
    int t;cin>>t;

    // memorization
    // vector<vector<int>> dp(n,vector<int>(t+1,-1));
    // cout<<sol(n-1,t,n,arr,dp);

    // tabulization
    vector<vector<bool>> dp(n,vector<bool>(t+1,0));
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    if(arr[0] <= t)dp[0][arr[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int k = 1; k <= t; k++){
            bool nonTake = dp[i-1][k];
            bool take = 0;
            if(arr[i] <= k)take = dp[i-1][k-arr[i]];

            dp[i][k] = (take | nonTake);
        }
    }
    cout<<dp[n-1][t];
    return 0;
}