#include<iostream>
using namespace std;

bool isPossible(int*arr,int n,int m,int curr_min){
    int stud = 1;
    int page_reading = 0;

    for (int i = 0; i < n; i++)
    {
        if (page_reading + arr[i] > curr_min)
        {
            stud++;
            page_reading = arr[i];
            if (stud > m)
            {
                return false;
            }
            
        }else{
            page_reading += arr[i];
        }
    }
        return true;
    
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,sum=0;
        cin>>n>>m;

        int* arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }

        int s = arr[n-1];
        int e = sum;
        int ans = __INT_MAX__;

        while (s<=e)
        {
            int mid = (s+e)/2;

            if(isPossible(arr,n,m,mid)){
                ans = min(ans,mid);
                e = mid - 1;
            }else
            {
                s = mid + 1;
            }
            
        }
        cout<<ans<<endl;
        

    }
    
 return 0;
}