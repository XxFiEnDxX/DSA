#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<pair<int,int>> s;

    s.insert(make_pair(10,1));
    s.insert(make_pair(10,60));
    s.insert(make_pair(20,30));
    s.insert(make_pair(40,10));
    s.insert(make_pair(40,80));

    s.erase(make_pair(10,1));
    s.insert(make_pair(10,10));

    auto it = s.lower_bound(make_pair(10,80));
    // cout<<it->first;
    cout<<(*it).first<<" and "<<it->second<<endl;
    for(auto p:s){
        cout<<p.first<<" and "<<p.second<<endl;
    }
    
    return 0;
}