#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class Graph{
    int v;
    vector<vector<int>> g;
    public:

    Graph(int size){
        v = size;
        g.resize(size);
    }

    void addEdges(int a, int b,bool undir = true){
        g[a].push_back(b);
        if(undir)g[b].push_back(a);
    }

    void bfs(int src,vector<bool> &visited){
        vector<bool> visited(v,false);
        queue<int> q;

        q.push(src);
        visited[src] = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int prt = q.front();
                q.pop();
                
                for(int nbrs:g[prt]){
                    if(!visited[nbrs]){
                        visited[nbrs] = true;
                        q.push(nbrs);
                    }
                }
                cout<<prt<<" ";
            }
            cout<<endl;

        }
        
    }

};
int main()
{

    Graph g(7);

    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(1,3);
    g.addEdges(2,4);
    g.addEdges(3,4);
    g.addEdges(3,5);
    g.addEdges(3,6);
    g.addEdges(5,6);

    vector<bool> visited(7,false);
    // g.bfs(0,visited);
    g.bfsRec(0,visited);

    return 0;
}