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

    int key; cin>>key;

    int i = 0;
    int j = m-1;

    while (i < n && j > -1)
    {
        if (arr[i][j] == key)
        {
        break;
        }
        if (arr[i][j] > key)
        {
            j--;
        }
        else
        {
            i++;
        }  
    }
    
    cout<<i<<" , "<<j;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

        return 0;
    }