#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    int n = 16;

    int ans = -1;

    for(int i = 1; i < n-2; i++){

        int cnt = 1;
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            int j = i;

            // count left
            while(j >= 1 && arr[j] > arr[j-1]){
                cnt++;
                j--;
            }

            // count right
            while(i <= n-2 && arr[i] > arr[i+1]){
                i++;
                cnt++;
            }
            ans = max(ans,cnt);
        }

    }

    cout<<ans;
    return 0;
}