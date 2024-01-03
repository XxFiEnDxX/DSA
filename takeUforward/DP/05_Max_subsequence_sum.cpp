#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solution(int n,vector<int>&arr,vector<int>&dp){
    if(n == 0)return arr[n];
    if(n < 0)return 0;
    if(dp[n] != -1)return dp[n];
    int pick = arr[n]+solution(n-2,arr,dp);
    int notPick = solution(n-1,arr,dp);
    dp[n] = max(pick,notPick);
    return dp[n];
}

int main()
{
    int n;cin>>n;
    vector<int> arr;
    vector<int> dp(n,-1);
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<solution(n-1,arr,dp);
    return 0;
}