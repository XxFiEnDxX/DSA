#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6};
    int n = arr.size();

    int ans = -1;
    unordered_set<int> s;
    for(auto ele:arr)s.insert(ele);

    for(auto ele:s){
        int parent = ele-1;
        if(s.find(parent) == s.end()){
            int nextEle = ele+1;
            int cnt = 1;
            while(s.find(nextEle) != s.end()){
                nextEle++;
                cnt++;
            }

            ans = max(ans,cnt);
        }

    }
    cout<<ans<<endl;
    return 0;
}