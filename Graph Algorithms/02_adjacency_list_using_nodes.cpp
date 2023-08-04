#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;


class Graph{
    unordered_map<string,list<string>*> m;

public:
    Graph(vector<string> cities){
        for(string city:cities){
            m[city] = new list<string>;
        }
    }

    void addEdges(string x,string y,bool undir = false){
        m[x]->push_back(y);

        if(undir){
            m[y]->push_back(x);
        }
    }

    void printAdjList(){
        for(auto city:m){
            cout<<city.first<<" --> ";
            for(auto ele:*city.second){
                cout<<ele<<",";
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