#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int min = INT_MAX;
    int max = INT_MIN;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        else if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    cout<<"Maximum value - "<<max<<endl;
    cout<<"Minimum value - "<<min<<endl;
    return 0;
}