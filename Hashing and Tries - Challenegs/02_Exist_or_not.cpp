#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int n, t, q, val;
    cin >> t;

    while (t--)
    {
        cin >> n;

        int *arr = new int[n];
        unordered_map<int, bool> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            m.insert({arr[i], true});
        }

        cin >> q;
        while (q--)
        {
            cin >> val;
            if (m.count(val))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}