#include<bits/stdc++.h>
using namespace std;
long long sol(int i, int cap, vector<int>& weight, vector<int>& value, vector<vector<long long>> &dp){
    if(i < 0)return 0;
    if(cap < 0)return 0;

    if(dp[i][cap] != -1)return dp[i][cap];

    long long NT = sol(i-1, cap, weight, value, dp);
    long long T = 0;
    if(weight[i] <= cap){
        T = value[i]+sol(i-1, cap-weight[i], weight, value, dp);
    }

    return dp[i][cap] = max(T,NT);
}
int main()
{
    int n;cin>>n;
    int cap;cin>>cap;

    vector<int> weight(n,0);
    vector<int> value(n,0);

    for(int i = 0; i < n; i++){
        cin>>weight[i];
        cin>>value[i];
    }

    vector<vector<long long>> dp(n+1,vector<long long>(cap+1,-1));
    cout<<sol(n-1,cap,weight,value,dp);
    return 0;
}