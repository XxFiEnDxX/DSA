#include<iostream>
using namespace std;

void genrate(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout<<arr[k]<<",";
            }
            cout<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
            cin>>arr[i];
    }
    
    genrate(arr,n);
    return 0;
}