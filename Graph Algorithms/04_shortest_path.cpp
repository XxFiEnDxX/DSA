#include <iostream>
#include <list>
#include <queue>
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

    void bfs(int n = 0,int m = -1)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *dist = new int[V]{0};
        int *parent = new int[V]{-1};
        parent[n] = -1;
        int d = 0;

        q.push(n);
        visited[n] = true;

        cout<<"=========================="<<endl;
        cout<<"BFS-> ";
        while (!q.empty())
        {
            int lvlsize = q.size();
            for (int i = 0; i < lvlsize; i++)
            {
                int cur = q.front();
                q.pop();

                cout << cur << ", ";
                dist[cur] = d;

                for (int ele : l[cur])
                {
                    if (visited[ele] == 0)
                    {
                        q.push(ele);
                        parent[ele] = cur;
                        visited[ele] = true;
                    }
                }
            }
            ++d;
        }
        cout<<endl;
        cout<<"=========================="<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"|Node ||Source Distance  |"<<endl;
        cout<<"--------------------------"<<endl;
        for (int i = 0; i < V; i++)
        {
            cout<<"|"<<i<<"    ||"<<dist[i]<<endl;
        }
        cout<<"--------------------------"<<endl;
        cout<<"=========================="<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"|Node ||Parent Node       |"<<endl;
        cout<<"--------------------------"<<endl;
        for (int i = 0; i < V; i++)
        {
            cout<<"|"<<i<<"    ||"<<parent[i]<<endl;
        }
        cout<<"--------------------------"<<endl;
        if(m != -1){
            int temp = m;
            while(temp != n){
                cout<<temp<<"--";
                temp = parent[temp];
            }
            cout<<n<<endl;
        }
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

    g.bfs(1,6);
    // g.printAdjList();
    return 0;
}