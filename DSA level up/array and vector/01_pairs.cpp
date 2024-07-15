#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;

    vector<int> arr(n,0);
    for(int i = 0 ; i < n; i++)cin>>arr[i];
    int sum;cin>>sum;

    pair<int,int> ans;
    unordered_map<int,int> map;

    for(int i = 0; i < n; i++){
        if(map.find(sum-arr[i]) != map.end()){
            ans = {sum-arr[i],arr[i]};
            break;
        }
        map[arr[i]] = i;
    }

    cout<<ans.first<<" "<<ans.second<<endl;
    
    return 0;
}