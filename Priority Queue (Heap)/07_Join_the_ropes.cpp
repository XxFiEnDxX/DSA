#include<iostream>
#include<queue>
using namespace std;

int join_ropes(int ropes[] ,int n){
    priority_queue<int,vector<int>,greater<int>> pq(ropes,ropes+n);
    int cost = 0;
    while (pq.size()>1)
    {
        int A = pq.top();
        pq.pop();

        int B = pq.top();
        pq.pop();

        int new_rope = A+B;
        pq.push(new_rope);
        cost += new_rope;
    }
    return cost;
}
int main()
{
    int arr[] = {4,3,2,6};
    int  n = 4;

    cout<< join_ropes(arr,n);
    return 0;
}