#include<bits/stdc++.h>
using namespace std;
bool sol(int i, int k, vector<int>& arr, vector<int>& st, int &sum){
    if(sum == k){
        for(int ele:st)cout<<ele<<" ";
        cout<<endl;
        return true;
    }
    if(i == arr.size())return false;

    st.push_back(arr[i]);
    sum += arr[i];
    if(sol(i+1,k,arr,st,sum))return true;

    st.pop_back();
    sum -= arr[i];
    if(sol(i+1,k,arr,st,sum))return true;

    return false;
}
int main()
{
    int n;cin>>n;
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++)cin>>arr[i];
    int k;cin>>k;

    vector<int> st;
    int sum = 0;
    sol(0,k,arr,st,sum);
    return 0;
}