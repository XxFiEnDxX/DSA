#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&dp,int i,vector<int>&arr){
    if(i==0)return 0;
    if(i==1)return abs(arr[0]-arr[1]);
    int a = abs(arr[i]-arr[i-1])-solve(dp,i-1,arr);
    int b = abs(arr[i]-arr[i-2])-solve(dp,i-2,arr);
    return min(a,b);   
}
int main(){
  int n;cin>>n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    int ele;cin>>ele;
    arr[i] = ele;
  }
  
  vector<int> dp(n+1,-1);
  int a = 0;
  int b = abs(arr[0]-arr[1]);
  for(int i = 2; i < n; i++){
    int one = abs(arr[i]-arr[i-1])+b;
    int two = abs(arr[i]-arr[i-2])+a;
    a = b;
    b = min(one,two);
  }
  cout<<b<<endl;
//   cout<<solve(dp,n-1,arr)<<endl;
  
  return 0;
}