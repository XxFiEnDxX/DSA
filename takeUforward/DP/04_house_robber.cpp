#include<bits/stdc++.h>
using namespace std;

int recursion(int n,vector<int> &arr){
    if(n < 0)return 0;

    int take = arr[n]+recursion(n-2,arr);
    int nonTake = recursion(n-1,arr);

    return max(take,nonTake);
}

int memorization(int n,vector<int> &arr,vector<int>&dp){
    if(n < 0)return 0;
    if(dp[n] != -1)return dp[n];
    int take = arr[n]+memorization(n-2,arr,dp);
    int nonTake = memorization(n-1,arr,dp);

    return dp[n] = max(take,nonTake);
}

int tabulation(vector<int> &arr){
    int n = arr.size();

    vector<int> dp(n,0);
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);

    for (int i = 1; i < n; i++)
    {
        int take = arr[i]+dp[i-2];
        int nonTake = dp[i-1];

        dp[n] = max(take,nonTake);
    }
    
    return dp[n];
}

int spaceOpti(vector<int> &arr){
    int n = arr.size();

    vector<int> dp(n,0);
    int a = 0;
    int b = arr[0];

    for (int i = 1; i < n; i++)
    {
        int take = arr[i]+a;
        int nonTake = b;
        
        a = b;
        b = max(take,nonTake);
    }

    return b;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);

    for (int i = 0; i < n; i++)
    {
        int ele;cin>>ele;
        arr[i] = ele;
    }

    cout<<recursion(n-1,arr)<<endl;

    vector<int> dp(n,-1);
    cout<<memorization(n-1,arr,dp)<<endl;

    cout<<tabulation(arr)<<endl;

    cout<<spaceOpti(arr)<<endl;

    
    return 0;
}