#include<iostream>
#include<algorithm>
using namespace std;
bool isPossible(int*arr,int p,int n,int min_time){
    int cnt = 1;

    int cur_time = 0;
    int cur_p = 1;

    for (int i = 0; i < n; i++)
    {
        cnt = 2;
        cur_time = arr[i];
        while (cur_time <= min_time)
        {
            cur_p++;
            cur_time += cnt*arr[i];
            cnt++;
            if (cur_p > p)
            {
                return true;
            }
            
        }  
                // cout<<cur_p<<" ";
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int p,n, fast=INT32_MAX;
        cin>>p>>n;

        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            fast = min(arr[i],fast);
        }

        int maxT = 0;
        for (int i = 1; i <= p; i++)
        {
            maxT += i*fast;
        }
        
        sort(arr,arr+n);

        int s = fast;
        int e = maxT;
        int ans = INT32_MAX;

        while (s<=e)
        {
            int mid = (s+e)/2;
            if(isPossible(arr,p,n,mid)){
                ans = min(ans,mid);
                e = mid -1;
            }else{
                s = mid +1;
            }
        }
        cout<<ans<<endl;
    }
    
 return 0;
}