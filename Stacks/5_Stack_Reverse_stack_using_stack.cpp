// reverse a stack
#include <iostream>
#include <stack>
using namespace std;

void transfer(stack<int> &s, stack<int> &s1, int n)
{
    for (int i = 0; i < n; i++)
    {
        s1.push(s.top());
        s.pop();
    }
}

void reverStack(stack<int> &s)
{
    stack<int> s1;

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        int x = s.top();
        s.pop();

        // transfer n-1-i ele from stacks;

        transfer(s, s1, n - i - 1);

        s.push(x);

        transfer(s1, s, n - i - 1);
    }
}

int main()
{
    stack<int> s, s2;

    for (int i = 1; i < 5; i++)
    {
        s.push(i);
    }

    // while (!s.empty())
    // {
    //     s2.push(s.top());
    //     s.pop();
    // }
    // while (!s2.empty())
    // {
    //     cout<<s2.top()<<", ";
    //     s2.pop();
    // }
    
    reverStack(s);
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    

    return 0;
}