#include <iostream>
using namespace std;

int maxSumSubmatrix(int **arr, int n, int m)
{
    int max = arr[n-1][m-1];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0;j--)
        {
            if (i < n-1)arr[i][j] += arr[i+1][j];
            if (j < m-1)arr[i][j] += arr[i][j+1];
            if (i < n-1 && j < m-1)arr[i][j] -= arr[i+1][j+1];

            if (max < arr[i][j])
            {
                max = arr[i][j];
            }
            
        }
    }

    return max;
}

int main()
{
    int n, m;
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

    cout<<"Max Sum "<<maxSumSubmatrix(arr,n,m)<<" ";
    return 0;
}