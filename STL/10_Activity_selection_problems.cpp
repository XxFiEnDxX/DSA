#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;

class nodeCompare
{
public:
    bool operator()(node A, node B)
    {
        if (A.second < B.second)
        {
            return 0;
        }
        else if(A.second > B.second){
            return 1;
        }
        else if(A.second == B.second)
        {
            if (A.first < B.first)
            {
                return 1;
            }else{
                return 0;
            }
        }
        return 0;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0, cur=0;
        cin >> n;

        priority_queue < node, vector<node>, nodeCompare> pq;

        for (int i = 0; i < n; i++)
        {
            int val1,val2;
            cin>>val1>>val2;

            pq.push({val1,val2});
        }
        
        for (int i = 0; i < n; i++)
        {
            node t = pq.top();
            if (cur <= t.first && t.first <= t.second)
            {
                cnt++;
                cur = t.second;
                // cout<<cur<<endl;
            }
            
            // cout<<t.first<<" "<<t.second<<endl;
            pq.pop();
        }

        cout<<cnt<<endl;
        
    }

    return 0;
}