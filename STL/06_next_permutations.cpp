#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[100]{0};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr[(i + 3) % n];
    }

    // rotate(arr,arr,arr+n);

    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    vector<int> v{1, 2, 3};

    // rotate(v.begin(),v.begin()+3,v.end());

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    // Next_permutation
    next_permutation(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    next_permutation(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    next_permutation(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    next_permutation(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    next_permutation(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    next_permutation(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}