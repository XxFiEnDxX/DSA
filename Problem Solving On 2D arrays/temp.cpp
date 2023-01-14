#include <iostream>
#include <vector>
using namespace std;

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        ans.push_back({1});

        vector<int> temp;
        for (int i = 1; i < numRows; i++)
        {
            for (int j = 0; j < ans[i - 1].size(); j++)
            {
                if (ans[i - 1].size() > 3)
                {
                    temp.push_back(1);
                    int a = j;
                    int b = j + 1;
                    temp.push_back(ans[i - 1][a] + ans[i - 1][b]);
                    temp.push_back(1);
                    ans.push_back(temp);
                    temp.clear();
                }
                else
                {
                    ans.push_back({1, 1});
                }
            }
        }

        return ans;
    }
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v = generate(n);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}