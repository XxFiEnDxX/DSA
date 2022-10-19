#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class stack
{
    queue<T> q1, q2;

public:
    void push(T x)
    {
        q1.push(x);
    }

    void pop()
    {
        if (q1.empty())
        {
            return;
        }
        while (q1.size() > 1)
        {
            T ele = q1.front();
            q2.push(ele);
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }

    T top()
    {
        while (q1.size() > 1)
        {
            T ele = q1.front();
            q2.push(ele);
            q1.pop();
        }

        T element = q1.front();
        q1.pop();
        q2.push(element);

        swap(q1, q2);
        return element;
    }

    int size()
    {
        return q1.size() + q2.size();
    }

    bool empty(){
        return q1.size() == 0;
    }
};

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();

    }
    
    return 0;
}