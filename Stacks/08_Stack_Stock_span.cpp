#include<iostream>
#include<stack>

using namespace std;
void stockSpan(int arr[],int n, int span[]){
    stack<int> s;

    s.push(0);
    span[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int cprise = arr[i];
        while (!s.empty() and arr[s.top()]<= arr[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            int preIdx = s.top();
            span[i] = i - preIdx;
        }else
        {
            span[i] = i + 1;
        }
        s.push(i);
    }
    
}

int main()
{
    int arr[] = {100,80,60,70,60,75,85};
    int n = sizeof(arr)/sizeof(int);
    int span[1000];
    stockSpan(arr,n,span);
    for (int i = 0; i < n; i++)
    {
        cout<<span[i]<<" ";
    }
    
    return 0;
}