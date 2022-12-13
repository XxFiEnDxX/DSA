#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n-1; i++)
        {
            int min = i;
            for (int j = i; j < n; j++)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
                
            }
            swap(arr[min],arr[i]);
        }
        
    }
    
}

int main()
{
    int arr[5] = {5,3,1,2,4};

    selectionSort(arr,5);

    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}