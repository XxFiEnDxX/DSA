#include<iostream>
#include<vector>
using namespace std;

int coinChangeRecur(vector<int>&coins, int m){
    // cout<<m<<" ";
    if(m == 0)return 0;
    int ans = INT16_MAX;
    for (int i = 0; i < coins.size() && m-coins[i] >= 0; i++)
    {
        ans = min(ans,coinChangeRecur(coins,m-coins[i]));
    }
    return ans+1;
}


int coinChangeTopDown(vector<int>&coins, int m, vector<int> &dp){
    // cout<<m<<" ";
    if(m == 0)return 0;
    if(m < 0)return INT32_MAX;
    int ans = INT32_MAX;

    if(dp[m] != INT32_MAX){
        return dp[m];
    }
    
    for (int i = 0; i < coins.size(); i++)
    {
        if(coinChangeTopDown(coins,m-coins[i],dp) != INT32_MAX){
            ans = min(ans,coinChangeTopDown(coins,m-coins[i],dp)+1);
        }
    }
    return dp[m] = ans;
}

int coinChangeBottomUp(vector<int> &coins, int m){
    vector<int> dp(m+1,INT32_MAX);
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if(i-coins[j] < 0) break;
            if(dp[i-coins[j]] != INT32_MAX){
                dp[i] = min(dp[i] , dp[i-coins[j]]+1);
            }
        }
    }
    return dp[m] == INT32_MAX?-1:dp[m];
}

int main()
{
    vector<int> coins{2,4,5};
    int m;
    cin>>m;

    cout<<coinChangeRecur(coins, m)<<endl;

    vector<int> dp(m+1,INT32_MAX);
    dp[0] = 0;
    int ans = coinChangeTopDown(coins,m,dp);
    if (ans == INT32_MAX)
    {
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    

    cout<<coinChangeBottomUp(coins, m)<<endl;
    return 0;
}