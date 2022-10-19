#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s,int x){
    if (s.empty())
    {
        s.push(x);
        return;
    }
    
    int data = s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(data);
}

void reverseStack(stack<int> &s)
{
    //base case
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();

    reverseStack(s);
    insertAtBottom(s,x);
}

int main()
{
    stack<int> s, s2;

    for (int i = 1; i < 5; i++)
    {
        s.push(i);
    }

    reverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ,";
        s.pop();
    }

    return 0;
}