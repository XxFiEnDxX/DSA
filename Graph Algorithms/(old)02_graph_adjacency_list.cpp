#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class graph
{
    unordered_map<string, list<pair<string, int>>> l;

public:
    void addEdge(string x, string y, int wgt, bool bidr = true)
    {
        l[x].push_back({y, wgt});
        if (bidr)
        {
            l[y].push_back({x, wgt});
        }
    }
    void printLL(){
        for (auto n : l)
        {
            string city = n.first;
            
            cout<<city<<"->";
            for (auto nbr : n.second)
            {
                cout<<"("<<nbr.first<<" "<<nbr.second<<"),";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph g;
    g.addEdge("A", "B", 20);
    g.addEdge("B", "D", 40);
    g.addEdge("A", "C", 10);
    g.addEdge("C", "D", 40);
    g.addEdge("A", "D", 50, false);
    g.printLL();
    return 0;
}