#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t, n;
    cin >> t ;
    while (t--)
    {
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;

        int d,n;
        cin>>n;
        float med;

        for (int i = 0; i < n; i++)
        {
            cin>>d;
            if (left.size() == 0 && right.size() == 0)
            {
                med = d;
                left.push(d);
            }

            else if (left.size() > right.size())
            {
                if (d < med)
                {
                    right.push(left.top());
                    left.pop();
                    left.push(d);
                }
                else
                {
                    right.push(d);
                }
                med = (left.top() + right.top()) / 2.0;
            }
            else if (left.size() == right.size())
            {
                if (d < med)
                {
                    left.push(d);
                    med = left.top();
                }
                else
                {
                    right.push(d);
                    med = right.top();
                }
            }
            else
            {
                if (d < med)
                {
                    left.push(d);
                }
                else
                {
                    left.push(right.top());
                    right.pop();
                    right.push(d);
                }
                med = (left.top() + right.top()) / 2.0;
            }

            cout << med << " ";
        }
        cout<<endl;
    }

    return 0;
}