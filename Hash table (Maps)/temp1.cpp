#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

// typedef pair<int, int> node;

// class comp
// {
// public:
//     bool operator()(node A, node B)
//     {
//         return A.second < B.second;
//     }
// };

int main()
{
    vector<int> v = {5,1,3,2,6,7,4};

    int n = 2;
    nth_element(v.begin(),v.end()-n,v.end());

    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl<<v[];
    priority_queue<node, vector<node>, comp> pq;

    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]]++;
    }
    
    for(auto i : m){
        pq.push({i.first,i.second});
    }


    // priority_queue<int> pq;
    // pq.push(v.begin(),v.end());

    // pq.push({1000, 1});
    // pq.push({1, 50});
    // pq.push({2, 5});
    // pq.push({10, 12});

    // cout << endl;

    // // int k = 2;
    while (!pq.empty())
    {
        cout << (pq.top()).first<< endl;
        // cout<<pq.top()<<" ";
        pq.pop();
    }

    return 0;
}
