#include <iostream>
#include <list>
using namespace std;

class queue
{
    int cs;
    list<int> l;

public:
    queue()
    {
        cs = 0;
    }

    bool isEmpty()
    {
        return cs == 0;
    }

    void push(int d)
    {
        l.push_back(d);
        cs++;
    }

    void pop()
    {
        if (!isEmpty())
        {
            cs--;
            l.pop_front();
        }
    }

    int front()
    {
        return l.front();
    }
};

int main()
{

    queue q;
    for (int i = 1; i <= 10; i++)
    {
        q.push(i);
    }

    while (!q.isEmpty())
    {
        cout<<q.front()<< " ";
        q.pop();
    }
    
    
    return 0;
}