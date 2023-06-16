#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;

    map<int,int> m;
    vector<int> v;
    int* arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if (m.count(arr[i]))
        {
            m[arr[i]]++;
        }
        else
        {
            m[arr[i]] = 1; 
        }
    }

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if (m.count(arr[i]) && m[arr[i]] > 0)
        {
            v.push_back(arr[i]);
            m[arr[i]]--;
        }
    }

    sort(v.begin(),v.end());

    cout<<"[";
    for (int i = 0; i < v.size(); i++)
    {
        if (i == v.size()-1)
        {
            cout<<v[i];  
        }
        else{
            cout<<v[i]<<", ";
        }
    }
    cout<<"]";
    
    
    return 0;
}