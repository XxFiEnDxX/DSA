#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int v=10){
        V = v;
        l = new list<int>[v]; //same as -> int *arr = new int[v];
    }

    void addEdge(int i ,int j,bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printAdjList(){
        for(int i = 0; i < V; i++){
            cout<<i<<"-->";
            for(int ele:l[i]){
                cout<<ele<<",";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);

    g.printAdjList();

    return 0;
}