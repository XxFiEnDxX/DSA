#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class graph
{
    unordered_map<int, list<int>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printLL()
    {
        for (auto node : l)
        {
            cout << node.first << "-> ";
            for (auto nbr : node.second)
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
    void bfs(int src)
    {
        unordered_map<int, bool> visited;
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

int main()
{
    graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.bfs(0);
    return 0;
}