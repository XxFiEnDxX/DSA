#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    int **arr = new int *[n];
    int **pref = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        pref[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pref[i][j] = arr[i][j];
            if (i > 0)
                pref[i][j] += pref[i - 1][j];
            if (j > 0)
                pref[i][j] += pref[i][j - 1];
            if (i > 0 && j > 0)
                pref[i][j] -= pref[i - 1][j - 1];
        }
    }

    pair<int, int> p1;
    pair<int, int> p2;
    cin >> p1.first;
    cin >> p1.second;
    cin >> p2.first;
    cin >> p2.second;

    int sumQuery;

    // cout<<pref[p2.first][p2.second]<<endl;
    if (p1.first == 0 && p1.second != 0)
    {
        sumQuery = pref[p2.first][p2.second] - pref[p2.first][p1.second - 1];
    }
    else if (p1.first != 0 && p1.second == 0)
    {
        sumQuery = pref[p2.first][p2.second] - pref[p1.first - 1][p2.second];
    }
    else if (p1.first == 0 && p1.second == 0)
    {
        sumQuery = pref[p2.first][p2.second];
    }
    else
    {
        sumQuery = pref[p2.first][p2.second] - pref[p1.first - 1][p2.second] - pref[p2.first][p1.second - 1] + pref[p1.first - 1][p1.second - 1];
    }

    cout << sumQuery << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << pref[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}