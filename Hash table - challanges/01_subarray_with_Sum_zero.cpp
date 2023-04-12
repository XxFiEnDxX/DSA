#include<iostream>
#include<unordered_set>
using namespace std;

string zeroCheck(int arr[],int n){
    int pre = 0;
    unordered_set<int> m;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        if (pre == 0 || m.find(pre) != m.end())
        {
            return "True";
        }
        
        m.insert(pre);
    }
    return "False";
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