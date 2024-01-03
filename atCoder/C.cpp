#include<iostream>
#include<vector>
using namespace std;
int solve(int n, int last, vector<vector<int>>&arr, vector<vector<int>>&dp){
    if(n == -1)return 0;
    int ans = 0;
    int sol = 0;
    for (int i = 0; i < 3; i++)
    {
        if(i != last){
            if(dp[n][i] != -1){
                sol = dp[n][i];
            }
            else{
                sol = arr[n][i]+solve(n-1,i,arr,dp);
                dp[n][i] = sol;
            }
            ans = max(ans,sol);
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
    // cout<<solve(n-1, 3, arr, dp)<<endl;
    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = arr[0][i];
    }

    for(int i = 1; i < n; i++){
        int ans = 0;
        int sol = 0;
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if(j!=k)dp[i][j] = dp[i-1][k]+arr[i][j];
                if(j!=k)ans = max(ans,dp[i][j]);

            }
        }
    }
    

    int ans = -1;
    for (int j= 0; j < 3; j++)
    {
        ans = max(ans,dp[n-1][j]);
    }
    cout<<ans<<endl;
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