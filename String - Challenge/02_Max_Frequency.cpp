#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// bool compare(pair<char,int> a,pair<char,int> b){
//     return a.second > b.second;
// }

int main()
{
    unordered_map<char,int> m;
    pair<char,int>max;
    max.first = '\0';
    max.second = 0;

    string str;
    cin>>str;

    for (int i = 0; i < str.length(); i++)
    {
        m[str[i]]++;
    }

    for(auto ele:m){
        // cout<<ele.first<<" "<<ele.second<<endl;
        if(max.second < ele.second){
            max.first = ele.first;
            max.second = ele.second;
            // cout<<max.first<<" "<<max.second<<" ";
        }
    }
    
    cout<<max.first;
    return 0;
}