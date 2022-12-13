#include<iostream>
using namespace std;

int Binary_search(int n,int key,int arr[]){
    int start=0;
    int end=(sizeof(arr)/sizeof(int))-1;
    int middle=(start+end)/2; 

    while (start<=end)
    {
        middle=(start+end)/2;
        if (arr[middle]==key)
        {
            return middle;
        }
        else if (arr[middle]<key)        
        {
            start=middle+1;
        }
        else if (arr[middle]>key)
        {
            end=middle-1;
        }
    }
    return -1;
}

int main()
{   
    int n=10;
    int key;

    int arr[10]{1,3,5,7,9,12,13,14,15,16};
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<"Enter the key you want to find-";
    cin>>key;
    
    int ans=Binary_search(n,key,arr);
    cout<<"Key present at "<<ans<<" index;"; 
    return 0;
}