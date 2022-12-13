#include <iostream>
using namespace std;

void Insertion_sort(int n, int arr[])
{
    for (int i = 1; i <= n - 1; i++)
    {
        int e = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j] > e)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = e;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Length of array-";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Insertion_sort(n, arr);
    return 0;
}