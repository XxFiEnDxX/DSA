#include<iostream>
#include<queue>
using namespace std;
int main()
{
    //push -> O(Log N);
    //pop -> O(Log N);
    //top -> O(1);

    priority_queue<int> pq; //Max Heap (Default)
    // priority_queue<int,vector<int>,greater<int>> pq; //Min Heap
    
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin>>no;
        pq.push(no);
    }
    
    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    return 0;
}