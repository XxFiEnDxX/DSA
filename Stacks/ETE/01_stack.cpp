#include <iostream>
using namespace std;

class stack
{
public:
    int stk[100];
    int n = 100;
    int tp = -1;
    void push(int d)
    {
        if (tp >= n)
        {
            cout << "Overflowed!" << endl;
        }
        else
        {
            tp++;
            stk[tp] = d;
        }
    }

    void pop()
    {
        if (tp < 0)
        {
            cout << "Under flow!";
        }
        else
        {
            tp--;
        }
    }

    bool empty()
    {
        if (tp >= 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    int top()
    {
        if (!empty())
        {
            return stk[tp];
        }

        return -1;
    }
};

int main()
{
    stack s;
    int arr[5]{1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = s.top();
        s.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}