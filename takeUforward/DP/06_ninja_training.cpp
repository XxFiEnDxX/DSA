#include<bits/stdc++.h>
using namespace std;
int recursion(int n, int d, vector<vector<int>>&arr){
    if(n < 0)return 0;
    int ans = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if(i != d){
            int temp = arr[n][i] + recursion(n-1,i,arr);
            ans = max(ans,temp);
        }
    }
    return ans;
}

int memoization(int n, int d, vector<vector<int>>&arr, vector<vector<int>>&dp){
    if(n < 0)return 0;
    int ans = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if(i != d){
            if(dp[n][i] == -1)dp[n][i] = arr[n][i] + memoization(n-1,i,arr,dp);
            ans = max(ans,dp[n][i]);
        }
    }
    return ans;
}

int tabulation(int n, vector<vector<int>>&arr){
    vector<vector<int>> dp(n,vector<int>(3,-1));
    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = arr[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int ans = -1;
            for (int k = 0; k < 3; k++)
            {
                if(j != k)ans = max(ans,dp[i-1][k]);
            }
            dp[i][j] = arr[i][j]+ans;
        }
    }
    int ans = -1;
    for(auto ele:dp[n-1]){
        ans = max(ans,ele);
    }
    return ans;
}
int main()
{
    int n,temp;cin>>n;
    vector<vector<int>> arr(n,vector<int>(3,0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>temp;
            arr[i][j] = temp;
        }
    }

    cout<<recursion(n-1,3,arr)<<endl;

    vector<vector<int>> dp(n,vector<int>(3,-1));
    cout<<memoization(n-1,3,arr,dp)<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    cout<<tabulation(n,arr)<<endl;

    return 0;
}