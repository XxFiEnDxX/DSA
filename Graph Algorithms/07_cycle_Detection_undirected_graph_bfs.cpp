#include <iostream>
#include <list>
#include <queue>
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

    bool cycleDetection(int n = 0)
    {
        queue<int> q;
        bool*visited = new bool[V]{0};
        int* parent = new int[V]{-1};

        q.push(n);
        visited[n] = true;

        while (!q.empty())
        {

            int cur = q.front();
            q.pop();

            cout << cur << ",";

            for (int ele : l[cur])
            {
                if(visited[ele] == 1){
                    if(ele != parent[cur]){
                        return true;
                    }
                }   
                else
                {
                    q.push(ele);
                    visited[ele] = true;
                    parent[ele] = cur;
                }
            }
        }
        return false;
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

    if(g.cycleDetection(1)){
        cout<<"Cycle is Present!";
    }
    else{
        cout<<"Cycle is not Present!";
    }
    // g.printAdjList();
    return 0;
}