#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        next_permutation(arr,arr+n);
        
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}