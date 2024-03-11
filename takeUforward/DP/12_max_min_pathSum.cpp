#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j,vector<vector<int>> &arr, vector<vector<int>> &dp){
    if(j < 0 || j > arr.size()-1)return -1e9;
    if(i == 0)return arr[i][j];
    if(dp[i][j] != -1)return dp[i][j];
    int s = solve(i-1,j,arr,dp);
    int l = solve(i-1,j-1,arr,dp);
    int r = solve(i-1,j+1,arr,dp);
    int ans = arr[i][j]+max(s,max(l,r));
    return dp[i][j] = ans;
}

int main()
{
    int n = 0;cin>>n;
    int m = 0;cin>>m;

    vector<vector<int>> arr(n,vector<int>(m,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int i = 0; i < m; i++){
        dp[0][i] = arr[0][i];
        // ans = max(ans,solve(n-1,i,arr,dp));
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int s = arr[i][j] + dp[i-1][j];
            int l = arr[i][j];
            if(j > 0){
                l += dp[i-1][j-1]; 
            }
            else{
                l += -1e9;
            }
            int r = arr[i][j];
            if(j+1 <= m-1){
                r += dp[i-1][j+1];
            }else{
                r += -1e9;
            }
            dp[i][j] = max(s,max(l,r));
        }
    }
    int ans = -1;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans,dp[n-1][i]);
    }
    cout<<ans<<endl;
    
    return 0;
}