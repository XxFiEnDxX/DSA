#include<iostream>
#include<unordered_map>
using namespace std;

int zeroCheck(int arr[],int n){
    int pre = 0;
    int len = 0;
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];

        if (pre == 0)
        {
            len = max(len,i+1);
        }
        else if(m.find(pre) != m.end()){
            len = max(len,i-m[pre]);
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
    int n;

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<zeroCheck(arr,n);
    return 0;
}