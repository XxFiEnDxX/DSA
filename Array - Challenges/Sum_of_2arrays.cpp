#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m, o;
    vector<int> v;

    cin >> n;
    int *arr1 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cin >> m;
    int *arr2 = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }


    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++)
    {
        num1 = num1 * 10 + arr1[i];
    }

    for (int j = 0; j < m; j++)
    {
        num2 = num2 * 10 + arr2[j];
    }

    int num3 = num1 + num2;

    while (num3 !=0)
    {
        int ele = num3%10;

        v.insert(v.begin(),ele);
        num3 /= 10;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<", ";
    }
    cout<<"END";
    
    // int o = max(n,m);
    // int *arr3 = new int[max(n,m)];

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int j = m - 1; j >= 0; j--)
    //     {

    //     }
    // }

    return 0;
}