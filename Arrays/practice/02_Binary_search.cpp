#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int key){
    int st = 0;
    int ed = n-1;
    int mid = (st+ed)/2;
    while (st<=ed)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        
        else if (key > arr[mid])
        {
            st = mid + 1;
        }else if (key < arr[mid])
        {
            ed = mid - 1;
        }
        
        return -1;
    }
    
}
int main()
{
    int n; cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int key; cin>>key;

    cout<<binarySearch(arr,n,key);
    

    return 0;
}