#include <iostream>
using namespace std;

void Selection_sort(int n, int arr[])
{
    int MinI;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        MinI = i;
        for (int j = i+1; j <= n - 1; j++)
        {
            if (arr[j] < arr[MinI])
            {
                MinI = j;
            }
        }
        swap(arr[i],arr[MinI]);
        // temp = arr[MinI];
        // arr[MinI] = arr[i];
        // arr[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
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

    Selection_sort(n, arr);
    return 0;
}