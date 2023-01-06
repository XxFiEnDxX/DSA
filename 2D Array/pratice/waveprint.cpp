#include <iostream>
using namespace std;
int main()
{
    int arr[20][20]{};
    int m, n;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for (int j = 0; j < m; j++)
    {
        if (j % 2 == 0)
        {
            // odd
            for (int i = 0; i < n; i++)
            {
                cout << arr[i][j]<<" ";
            }
        cout<<endl;
        }
        else
        {
            // even
            for (int i = n - 1; i >= 0; i--)
            {
                cout << arr[i][j]<<" ";
            }
        cout<<endl;
        }
    }
        return 0;
    }