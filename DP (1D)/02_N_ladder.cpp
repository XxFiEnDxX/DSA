#include<iostream>
#include<vector>
using namespace std;

int normal(int n, int k){ // O(k^n) Time
    if(n == 0)return 1;
    if(n < 0)return 0;

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += normal(n-i,k);
    }
    return ans;
}

    int recTopBottom(int n,int k,vector<int> &dp){ // O(N)
        if(n == 0)return 1;
        if(n < 0)return 0;

        if(dp[n] != 0)return dp[n];

        for (int i = 1; i <= k; i++)
        {
            dp[n] += recTopBottom(n-i,k,dp);
        }
        return dp[n];
    }

    int BottomUp(int n, int s){ // O(NK) time
        vector<int> dp(n+1,0);  // O(N) Space

        dp[0] = 1;
        dp[1] = 1;
        int k;
        for (int i = 2; i <= n; i++) 
        {
            k = i-1;
            for (int j = 0; j < s && k >= 0; j++)
            {
                dp[i] += dp[k--];
            }
        }
        return dp[n];
    }

    int optimisedDP(int n, int  k){ // O(N) Time
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int idx = i-k-1;
            if(idx >= 0)dp[i] = 2*dp[i-1] - dp[idx];
            else dp[i] = 2*dp[i-1];
        }
        return dp[n];
    }

int main()
{
    int n,k;
    cin>>n>>k;

    cout<<normal(n,k)<<endl;

    vector<int> dp(n+1,0);
    cout<<recTopBottom(n,k,dp)<<endl;

    cout<<BottomUp(n,k)<<endl;

    cout<<optimisedDP(n,k)<<endl;

    return 0;
}