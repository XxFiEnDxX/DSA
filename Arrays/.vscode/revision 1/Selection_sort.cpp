#include <iostream>
using namespace std;

void Selection_sort(int &n, int arr[])
{
    int MinI = 0;
    for (int i = 0; i < n; i++)
    {
        MinI = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[MinI])
            {
                MinI = j;
            }
        }
        swap(arr[i],arr[MinI]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n, key;
    cout << "Enter The length of the array- ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Selection_sort(n, arr);

    return 0;
}