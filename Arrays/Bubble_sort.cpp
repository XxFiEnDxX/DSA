#include<iostream>
using namespace std;

void Bubble_sort(int n,int arr[]){
    for (int i = 1; i <= n-1; i++)     //i{1 to n-1}
    {
        for (int j = 0; j < n-i; j++)  //j{0 to n-i}
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        } 
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
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

    Bubble_sort(n,arr);

    return 0;
}