#include<iostream>
using namespace std;

bool compare(int a,int b){
    return a < b;
}

void BubbleSort(int arr[], int n, bool (&cmp)(int a,int b)){
    int cnt=0;
    for (int i = 1; i < n; i++)
    {
        for (int  j = 0; j < n-i; j++)
        {
            if (cmp(arr[j],arr[j+1]))
            {
                swap(arr[j],arr[j+1]);
            }   
        }  
    }   
}
int main()
{
    int n=10;
    int arr[20]{9,1,8,2,3,6,5,4,10,7};

    BubbleSort(arr , n , compare);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}