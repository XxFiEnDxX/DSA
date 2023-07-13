#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{
    public:
    string name;
    list<string> nbrs;

    Node(string name){
        this->name = name;
    }
};

class Graph{
    unordered_map<string,Node*> m;

public:
    Graph(vector<string> cities){
        for(string city:cities){
            m[city] = new Node(city);
        }
    }

    void addEdges(string x,string y,bool undir = false){
        m[x]->nbrs.push_back(y);

        if(undir){
            m[y]->nbrs.push_back(x);
        }
    }

    void printAdjList(){
        for(auto city:m){
            cout<<city.first<<" --> ";
            for(auto ele:city.second->nbrs){
                cout<<ele<<" ,";
            }
            cout<<endl;
        }
    }
};
int main()
{
    vector<string> cities = {"delhi","london","paris","newyork"};

    Graph g(cities);
    g.addEdges("delhi","london");
    g.addEdges("newyork","london");
    g.addEdges("delhi","paris");
    g.addEdges("paris","newyork");

    g.printAdjList();
    return 0;
}