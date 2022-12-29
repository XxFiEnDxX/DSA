#include <iostream>
using namespace std;

int storeOcc(int arr[], int i, int n, int key, int out[], int j)
{
    if (i == n)
    {
        return j;
    }
    if (arr[i] == key)
    {
        out[j] == i;
        return storeOcc(arr, i + 1, n, key, out, j + 1);
    }
    return storeOcc(arr, i + 1, n, key, out, j);
}

void allOccurence(int arr[], int i, int n, int key)
{
    if (i == n)
    {
        return;
    }

    if (arr[i] == key)
    {
        cout << key << " ";
    }

    allOccurence(arr, i + 1, n, key);
}

int main()
{
    int arr[] = {1, 2, 3, 2, 5, 6, 2, 8};
    int key;
    cin >> key;
    int n = sizeof(arr) / sizeof(int);

    allOccurence(arr, 0, n, key);

    int out[100];
    int cnt = storeOcc(arr, 0, n, key, out, 0);
    cout << cnt << endl;
    return 0;
}