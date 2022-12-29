#include <iostream>
using namespace std;

int lastOccurence(int arr[], int n, int key)
{
    if (n == 0)
    {
        return -1;
    }
    int temp = lastOccurence(arr + 1, n - 1, key);

    if (arr[0] == key && temp == -1)
    {
        return 0;
    }

    if (temp != -1)
    {
        return temp + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 2, 8};
    int key;
    cin >> key;
    int n = sizeof(arr) / sizeof(int);

    cout << lastOccurence(arr, n, key) << endl;
    return 0;
}