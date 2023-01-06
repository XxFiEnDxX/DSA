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

    for (int row = 0; row < n; row++)
    {
        int strt = 0;
        int end = m - 1;
        
        while (strt <= end)
        {
            swap(arr[row][strt++],arr[row][end--]);
        }  
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

        return 0;
    }