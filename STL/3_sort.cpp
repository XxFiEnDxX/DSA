#include <iostream>
#include <algorithm>
using namespace std;

// Define a comparator Function
bool compare(int a, int b)
{
    // cout<<"comparing "<<a<<" and "<<b<<endl;
    return a < b;
}
int main()
{
    int n = 10;
    int arr[100]{9, 3, 7, 5, 6, 1, 2, 8, 10, 4};

    sort(arr, arr + n, compare);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}