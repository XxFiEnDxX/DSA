#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a,int b){
    return a>b;
}

int main()
{
    int n;
    cout << "Length of array-";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // sort(arr,arr+n,function()) 
    // arr-> array n-> length func-> name as parameter
    sort(arr, arr + n, compare);

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}