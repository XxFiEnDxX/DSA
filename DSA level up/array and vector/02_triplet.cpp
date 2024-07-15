#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int sum;cin>>sum;

    vector<vector<int>> res;
    

    for(int i = 0; i < n-2; i++){
        int curSum;

        int j = i+1;
        int k = n-1;

        while(j < k){
            curSum = (arr[i]+arr[j]+arr[k]);

            if(curSum == sum){
                res.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
            }
            else if(curSum > sum)k--;
            else j++;
        }
    }

    for(auto ele:res){
        cout<<ele[0]<<" "<<ele[1]<<" "<<ele[2]<<" "<<endl;
    }
    
    return 0;
}