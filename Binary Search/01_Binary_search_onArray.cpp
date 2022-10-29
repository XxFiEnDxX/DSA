#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int key){
    int st = 0;
    int ed = n-1;
    int mid = (st + ed)/2;
    while (st < ed)
    {
        mid = (st + ed)/2;
        if (arr[mid] == key)
        {
            return mid;
        }else if (arr[mid] < key)
        {
            st = mid + 1;
        }else
        {
            ed = mid - 1;
        }
    }
    return -1;
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

    int key ;
    cin>>key;

    cout<<"Key present at index "<<binarySearch(arr,n,key)<<endl;

    return 0;
}