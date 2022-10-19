#include <iostream>
using namespace std;

void spiralPrint(int arr[][20],int m,int n){
    int sr = 0;
    int sc = 0;
    int er = m-1;
    int ec = n-1;
    while (sr<=er && sc<=ec)
    {
        for (int i = sc; i <= ec; i++)
        {
            cout<<arr[sr][i]<<" ";
        }
            sr++;
        for (int i = sr; i <= er; i++)
        {
            cout<<arr[i][ec]<<" ";
        }
            ec--;
        for (int i = ec; i >= sc; i--)
        {
            cout<<arr[er][i]<<" ";
        }
            er--;
        for (int i = er; i >= sr; i--)
        {
            cout<<arr[i][sc]<<" ";
        }
            sc++;
        
    }
    
}
int main()
{
    int m, n;
    cin >> m >> n;

    int arr[20][20];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    spiralPrint(arr,m,n);
    return 0;
}