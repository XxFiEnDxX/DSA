#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }

    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
    }
    bubbleSort(arr, n - 1);
}

void bubbleSortRecursive(int arr[], int j, int n)
{
    if (n == 1)
    {
        return;
    }
    if (j == n - 1)
    {
        return bubbleSortRecursive(arr, 0, n-1);
    }

    if (arr[j] > arr[j + 1])
    {
        swap(arr[j], arr[j + 1]);
    }

    bubbleSortRecursive(arr, j+1, n);
}
int main()
{
    int arr[5] = {2, 1, 3, 5, 4};
    int n = 5;

    bubbleSortRecursive(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}