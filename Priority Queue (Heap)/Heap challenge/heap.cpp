#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {3,1,2,5,6,4};

    nth_element(v.begin(),v.begin()+3,v.end());

    for (auto i : v)
    {
        cout<<i<<" ";
    }
    

    return 0;
}