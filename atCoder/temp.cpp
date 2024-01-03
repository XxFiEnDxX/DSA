#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int n, int last, vector<vector<int>>&arr, vector<vector<int>>&dp){
    if(n == -1)return 0;
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if(i != last){
            ans = max(ans,(arr[i]+solve(n-1,i,arr,dp)));
        }
    }
    return ans;
    
}
int main()
{
    int n;cin>>n;
    vector<vector<int>> arr(n,vector<int>(3,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[i][j];
        }
    }
    
    vector<vector<int>> dp(n,vector<int>(3,-1));
    cout<<solve(n-1, 3, arr, dp)<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
        
    }
    

    return 0;
}