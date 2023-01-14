#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int compare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);

    // then append X at the end of Y
    string YX = Y.append(X);

    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;
}
int main()
{
    int n, t;
    string ele;
    cin >> t;
    while (t--)
    {
    vector<string> v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ele;
            v.push_back(ele);
        }
        sort(v.begin(), v.end(), compare);

        for (int i = 0; i < n; i++)
        {
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}