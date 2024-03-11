#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int d[3] = {0,-1,1};
    int dp[71][71][71];
    int sol(int i, int j1, int j2, vector<vector<int>>& grid,int& n ,int& m){

        if(i == n)return 0;

        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)return INT_MIN;
        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];
        int ans = 0;
        for(int dj1 = 0; dj1 < 3; dj1++){
            for(int dj2 = 0; dj2 < 3; dj2++){
                ans = max(ans,sol(i+1,j1+d[dj1],j2+d[dj2],grid,n,m));
            }
        }
        ans += (j1 == j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
        return dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof dp);
        return sol(0,0,m-1,grid,n,m);
    }
};
int main()
{
    return 0;
}