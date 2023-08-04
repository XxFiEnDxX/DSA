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

    void addEdge(int i, int j)
    {
        l[i].push_back(j);
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

    bool dfs(int node,vector<bool>&visited, vector<bool>&stack){
        visited[node] = true;
        stack[node] = true;

        for(int nbr:l[node]){
            if(stack[nbr] == true){
                return true;
            }
            else if (visited[nbr]==false)
            {
                if(dfs(nbr,visited,stack)){
                    return true;
                }
            }
            
        }

        stack[node] = false;
        return false;
        
    }

    bool cycleDetection() //wrapper func()
    {
        vector<bool> visited(V,false);
        vector<bool> stack(V,false);

        for (int i = 0; i < V; i++)
        {
            int src = i;
            if (dfs(src,visited,stack))
            {
                return true;
            }
            
        }
        return false;
        
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(5, 4);


    if(g.cycleDetection()){
        cout<<"Cycle is Present!";
    }
    else{
        cout<<"Cycle is not Present!";
    }
    // g.printAdjList();
    return 0;
}