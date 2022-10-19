#include <iostream>
using namespace std;

void Linear_search(int &n, int arr[], int &key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Key is present at " << i << " index";
            break;
        }
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
        cout << "Enter the key- ";
        cin >> key;

        Linear_search(n, arr, key);

        return 0;
    }