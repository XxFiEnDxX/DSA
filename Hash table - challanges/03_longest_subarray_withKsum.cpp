#include<iostream>
#include<unordered_map>
using namespace std;

int ksumCheck(int arr[],int n,int k){
    int pre = 0;
    int len = 0;
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];

        if (pre == k)
        {
            len = max(len,i+1);
        }
        else if(m.find(pre-k) != m.end()){
            len = max(len,i-m[pre-k]);
        }
        else{
            m.insert({pre,i});
        }
    }
    return len;
}

int main()
{
    int arr[100];
    int n,k;

    cin>>n;
    cin>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<ksumCheck(arr,n,k);
    return 0;
}