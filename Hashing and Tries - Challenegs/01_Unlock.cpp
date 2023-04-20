#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;

    int *arr = new int[n];
    unordered_map<int,int> m;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        m.insert({arr[i],i});
    }

    int pos;
    for (int i = n; i >= 1; i--)
    {
        if (k == 0)
        {
            break;
        }
        
        pos = n-i;
        if(arr[pos] != i){
            swap(arr[pos],arr[m[i]]);
            int temp = m[i];
            m[i] = pos;
            m[arr[temp]] = temp;
            k--;
        }
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}