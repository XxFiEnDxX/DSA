//time comp. ->  O(n^3)

#include <iostream>
using namespace std;

void subarray(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        for (int k = i; k <n; k++)
        {
            for (int j = i; j <= k; j++)
            {
                cout << arr[j] << " ";
            }
            cout << endl;
        }
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

    subarray(n, arr);
    return 0;
}