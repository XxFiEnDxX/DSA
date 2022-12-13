#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> node;
vector<int> mergeksorted(vector<vector<int>> arr)
{
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0],{i,0}});
    }
    
    while (!pq.empty())
    {
        node top = pq.top();
        pq.pop();

        int ele = top.first;
        int x = top.second.first;
        int y = top.second.second;

        result.push_back(ele);
        if (y+1 < arr[x].size())
        {
            pq.push({arr[x][y+1],{x,y+1}});
        }
    }
    return result;
}
int main()
{
	int k,n;
	cin>>k>>n;

	vector<vector<int>> arr;

    vector<int> temp;
    int num;
	for(int i = 0; i<k; i++){
        temp.clear();
		for(int j=0; j<n; j++){
            cin>>num;
            temp.push_back(num);
		}
        arr.push_back(temp);
	}
    vector<int>v = mergeksorted(arr);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}