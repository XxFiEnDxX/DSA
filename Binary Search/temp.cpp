#include<iostream>
using namespace std;

bool isPossible(int*arr,int n,int m,int cur_min){
    int stud = 1;
    int page_readed =  0;

    for (int i = 0; i < n; i++)
    {
        if (page_readed + arr[i] > cur_min)
        {
            stud++;
            page_readed = arr[i];
            if (stud > m)
            {
                return false;
            }
            
        }else{
            page_readed+=arr[i];
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
        int ans = INT16_MAX;

        while (s<=e)
        {
            int mid = (s+e)/2;
            if(isPossible(arr,n,m,mid)){
                ans = min(ans,mid);
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        cout<<ans<<endl;
        

    }
    
 return 0;
}