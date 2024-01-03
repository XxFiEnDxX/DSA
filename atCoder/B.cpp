#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;cin>>n;
    int k;cin>>k;
    if(k > n) k = n-1;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        int ele;cin>>ele;
        arr[i] = ele;
    }
    
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = abs(arr[0]-arr[1]);
    
    for(int i = 2; i < n; i++){
        int ans = INT32_MAX;
        int t = i-1;
        for (int j = 0; j < k && t >= 0; j++)
        {
            // int temp = dp[t]+val;
            ans = min(ans,dp[t]+abs(arr[i]-arr[t]));
            t--;
        }
        
        dp[i] = ans;
    }
    
    cout<<dp[n-1]<<endl;


  
  return 0;
}