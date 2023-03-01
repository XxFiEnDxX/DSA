#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);

    int key = 5;
    auto it = find(arr, arr + n, key);

    int index = it - arr;

    if (index == n)
    {
        cout << "Key is not present !" << endl;
    }
    else
    {
        cout << "Present at index " << index << endl;
    }
    return 0;
}