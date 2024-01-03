#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int rec(int n,vector<int>&value,vector<int>&wt,int lim){
    if(n == 0){
        return (wt[0] <= lim)?value[0]:0;
    }
    int nt = 0+rec(n-1,value,wt,lim);
    int t = INT32_MIN;
    if(wt[n] <= lim){
        t = value[n]+rec(n-1,value,wt,(lim-wt[n]));
    } 
    return max(t,nt);
}

int memo(int n,vector<int>&value,vector<int>&wt,int lim,vector<vector<int>>&dp){
    if(n == 0){
        return (wt[0] <= lim)?value[0]:0;
    }
    if(dp[n][lim] != -1)return dp[n][lim];
    int nt = 0+memo(n-1,value,wt,lim,dp);
    int t = INT32_MIN;
    if(wt[n] <= lim){
        t = value[n]+memo(n-1,value,wt,(lim-wt[n]),dp);
    } 
    dp[n][lim] = max(t,nt);
    return dp[n][lim];
}

int main()
{
    int n;cin>>n;
    vector<int> value;
    vector<int> weight;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        weight.push_back(ele);
        cin>>ele;
        value.push_back(ele);
        // cout<<value[i]<<" "<<weight[i]<<endl;
    }
    int lim;cin>>lim;
    
    // cout<<rec(n-1,value,weight,lim)<<endl;

    vector<vector<int>> dp(n+1,vector<int>(lim+1,-1));
    // cout<<memo(n-1,value,weight,lim,dp)<<endl;

    for (int i = weight[0]; i <= lim; i++)dp[0][i] = value[0];

    for(int i = 1; i < n; i++){
        for (int j = 0; j <= lim; j++)
        {
            int nt = 0+dp[i-1][j];
            int t = INT32_MIN;
            if(weight[i] <= j){
                t = value[i]+dp[i-1][j-weight[i]];
            } 
            dp[i][j] = max(t,nt);
        }
    }
    cout<<dp[n-1][lim]<<endl;
    
    return 0;
}