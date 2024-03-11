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
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    

    int t;cin>>t;
    vector<vector<int>> dp(n,vector<int>(t+1,-1));

    cout<<sol(n-1,t,n,arr,dp);
    
    return 0;
}