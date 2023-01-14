#include <iostream>
using namespace std;
bool searchInMatrix(int **arr, int n, int m, int key)
{
    int i = 0;
    int j = m - 1;
    while (i < n && j >= 0)
    {
        if (key == arr[i][j])
        {
            return true;
            // cout << "present" << endl;
            // cout << "Key present at i,j index " << i << " " << j << endl;
            break;
        }
        else if (key > arr[i][j])
            i++;
        else if (key < arr[i][j])
            j--;
    }

    return false;

}
int main()
{
    int n, m, key;
    cin >> n >> m;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    // Array elements Input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cin >> key;

    cout<<searchInMatrix(arr, n, m, key);
    return 0;
}