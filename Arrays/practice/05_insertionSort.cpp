#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
        int e = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>e)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = e;
    }
    
    
}

int main()
{
    int arr[5] = {5,3,1,2,4};

    insertionSort(arr,5);

    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}