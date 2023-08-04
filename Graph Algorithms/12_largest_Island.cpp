#include<iostream>
#include<vector>
#include<queue>
using namespace std;
    int helper(vector<vector<char>>& grid, int i, int j, int m, int n){
        grid[i][j] = '0';
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};

        int cnt = 1;
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            int ci = q.front().first;
            int cj = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int ni = dx[k]+ci;
                int nj = dy[k]+cj;
                
                if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == '1'){
                    ++cnt;
                    grid[ni][nj] = '0';
                    q.push({ni,nj});
                }
            }
        }
        return cnt;
    }
    int largestIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans = max(ans,helper(grid,i,j,m,n));
                }
            }
        }

        return ans;
    }
int main()
{
    vector<vector<char>> grid =    {{'1','0','0','1','0'},
                                    {'1','0','1','0','0'},
                                    {'0','0','1','0','1'},
                                    {'1','0','1','1','1'},
                                    {'1','0','1','1','0'}};

    cout<<largestIslands(grid);
    return 0;
}