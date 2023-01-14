#include <iostream>
using namespace std;

bool check(int *arr, int n)
{
    int i = 0;
    int j = n - 1;

    while(i <= j)
    {
        if (arr[i++] != arr[j--])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (check(arr,n))
    {
        cout<<"true";
    }else{
        cout<<"false";
    }
    
    return 0;
}