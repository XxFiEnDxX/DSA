#include<iostream>
#include<vector>
#include<set>
using namespace std;


class Node{
    public:
    int i,j,dist;
    Node(int i, int j, int dist){
        this->i = i;
        this->j = j;
        this->dist = dist;
    }
};

class compare{
    public:
    bool operator()(const Node &a,const Node &b){
        return a.dist <= b.dist;
    }
};

int shortest_path(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    //directions
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    vector<vector<int>> distance(m,vector<int>(n,INT32_MAX));
    set<Node,compare> s;

    distance[0][0] = grid[0][0];
    s.insert(Node(0,0,distance[0][0]));

    while (!s.empty())
    {
        auto cur = s.begin();
        int distTillNow = cur->dist;
        int i = cur->i;
        int j = cur->j;
        s.erase(cur);

        for (int k = 0; k < 4; k++)
        {
            int ni = dx[k]+i;
            int nj = dy[k]+j;

            if(ni >= 0 && nj >= 0 && ni < m && nj < n && distTillNow+grid[ni][nj] < distance[ni][nj]){
                Node temp(ni,nj,distance[ni][nj]);
                if(s.find(temp) != s.end()){
                    s.erase(s.find(temp));
                }

                int newDist = distTillNow+grid[ni][nj];
                distance[ni][nj] = newDist;
                s.insert(Node(ni,nj,newDist));
            }
        }
        

    }
    return distance[m-1][n-1];

}
int main()
{
    vector<vector<int>> grid = {{31,100,65,12,18},
                                {10,13,47,157,6},
                                {100,113,174,11,33},
                                {88,124,41,20,140},
                                {99,32,111,41,20}};

    cout<<shortest_path(grid);
    
    return 0;
}