#include<iostream>
using namespace std;

void Linear_search(int &n,int &key,int arr[])
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==key)
        {
            cout<<"Key founded at "<<i<<" index";
            break;
        }   
    }
}

int main()
{
    int n,key;
    cout<<"Length of array-";
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the key you want to find-";
    cin>>key;

    Linear_search(n,key,arr);
    
    return 0;
}