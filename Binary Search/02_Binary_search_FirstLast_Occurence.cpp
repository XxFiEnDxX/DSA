#include<iostream>
using namespace std;
int first_occurence(int arr[],int n,int key){
    int st = 0;
    int ed = n-1;
    int ans = -1;
    int mid = (st + ed)/2;
    while (st < ed)
    {
        mid = (st + ed)/2;
        if (arr[mid] == key)
        {
            ans = mid;
            ed = mid - 1;
        }else if (arr[mid] < key)
        {
            st = mid + 1;
        }else
        {
            ed = mid - 1;
        }
    }
    return ans;
}
int last_occurence(int arr[],int n,int key){
    int st = 0;
    int ed = n-1;
    int ans = -1;
    int mid = (st + ed)/2;
    while (st < ed)
    {
        mid = (st + ed)/2;
        if (arr[mid] == key)
        {
            ans = mid;
            st = mid + 1;
        }else if (arr[mid] < key)
        {
            st = mid + 1;
        }else
        {
            ed = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {1,2,2,5,8,8,8,8,10,12,15,15,20};
    int n = sizeof(arr)/sizeof(int);
    int key = 8;
    cout<<"first occurence - "<<first_occurence(arr,n,key)<<endl;
    cout<<"last occurence - "<<last_occurence(arr,n,key)<<endl;
    return 0;
}