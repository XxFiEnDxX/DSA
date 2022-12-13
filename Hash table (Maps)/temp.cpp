#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;
int main()
{
    unordered_map<int, int> f;

    vector<int> v = {1,1,2,3,2,1,3,4,4,6,1,4,4,4,4};

    for (int i = 0; i < v.size(); i++)
    {
        f[v[i]] += 1;
    }

    for (auto e : f)
    {
        cout<<e.first<<" : "<<e.second<<endl;
    }
    
    return 0;
}