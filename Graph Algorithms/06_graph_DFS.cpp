#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
    unordered_map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src,map<T,bool> &visited){
        visited[src] = true;
        cout<<src<<" ";
        
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr,visited);
            }
            
        }
        
    }

    void dfs(T src)
    {
        map<T,bool> visited;

        for(auto p:l){
            T node = p.first;

            visited[src] = false;
        }
        dfs_helper(src,visited);
    }
};

int main()
{
    graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.dfs(0);

    return 0;
}