#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Graph{
    int V;
    vector<vector<pair<int,int>>> g;
    public:
    Graph(int size){
        V = size;
        g.resize(size);
    }

    void addEdges(int u,int v,int weight){
        g[u].push_back({weight,v});
        g[v].push_back({weight,u});
    }

    int dijkshtra(int src,int dest){
        //data  structure
        vector<int> dist(V,INT16_MAX);
        set<pair<int,int>> s;

        dist[src] = 0;
        s.insert({0,src});

        //1.
        while(!s.empty()){
            auto it = s.begin();

            int node = it->second;
            int distTillNow = it->first;

            s.erase(it);

            //iterator over the nbrs of node
            for(auto nbrPair : g[node]){
                int nbr = nbrPair.second;
                int nbrdist = nbrPair.first;

                if(distTillNow + nbrdist < dist[nbr]){
                    auto f = s.find({dist[nbr],nbr});
                    if(f != s.end()){
                        s.erase(f);
                    }

                    dist[nbr] = distTillNow+nbrdist;
                    s.insert({dist[nbr],nbr});
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            cout<<i<<"->"<<dist[i]<<endl;
        }
        

        return dist[dest];
    }
};

int main()
{
    Graph g(5);
    
    g.addEdges(0,1,1);
    g.addEdges(1,2,1);
    g.addEdges(0,2,4);
    g.addEdges(0,3,7);
    g.addEdges(3,2,2);
    g.addEdges(3,4,3);

    cout<<g.dijkshtra(0,4);
    return 0;
}