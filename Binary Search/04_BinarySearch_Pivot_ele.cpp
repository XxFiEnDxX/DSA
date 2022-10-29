#include <iostream>
using namespace std;

int find_key(int a[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) >> 1;
    while (s <= e)
    {
        mid = (s + e)/2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[s] <= a[mid])
        {
            if (a[s] <= key && key <= a[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else if(a[e] >= a[mid])
        {
            if (a[e] >= key && key >= a[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int a[10000];
    int key, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> key;

    cout<<find_key(a,n,key)<<endl;
    return 0;
}