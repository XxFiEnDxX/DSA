#include <iostream>
#include <list>
#include <stack>
#include <map>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v = 10)
    {
        V = v;
        l = new list<int>[v];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            for (int ele : l[i])
            {
                cout << ele << ",";
            }
            cout << endl;
        }
    }

    void dfshelper(int src,bool *visited){
        visited[src] = true;
        cout<<src<<", ";
        for(int nbrs:l[src]){
            if(visited[nbrs] == 0){
                dfshelper(nbrs,visited);
            }
        }
        return;
    }

    void dfs(int src = 0)
    {
        cout<<"DFS -> ";
        bool* visited = new bool[V]{0};
        dfshelper(src,visited);
    }
};

int main()
{
    Graph g(7);

    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.dfs(1);
    // g.printAdjList();
    return 0;
}