#include<iostream>
#include<vector>
using namespace std;

int cnt = 0;
int funcRec(int n){ //normal recursion
    cnt++;
    if(n == 0 || n == 1)return n;
    return funcRec(n-1) + funcRec(n-2);
}

int funcDP(int n, vector<int> &dp){ //top - down DP (memorisation)
    if( n == 0 || n == 1)return n;
    if(dp[n] != 0){
        return dp[n];
    }
    dp[n] = funcDP(n-1,dp)+funcDP(n-2,dp);
    return dp[n];
}

int funcDPiter(int n){  //bottom up DP
    vector<int> dp(n+1,0);
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n;
    cout<<"Enter the value of N-";
    cin>>n;

    cout<<funcRec(n)<<endl;
    cout<<cnt;

    // vector<int> dp(n+1,0);
    // cout<<funcDP(n,dp);
    // cout<<funcDPiter(n);
    return 0;
}