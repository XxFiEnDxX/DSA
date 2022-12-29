#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int key){
    if (n == 0)
    {
        return -1;
    }

    if (arr[0] == key)
    {
        return 0;
    }

    int temp = linearSearch(arr+1,n-1,key);

    if (temp != -1)
    {
        return temp+1;
    }
    return -1;  
}

int main()
{
    int arr[] = {1,2,3,4,5,6,77,8};
    int key;
    cin>>key;
    int n = sizeof(arr)/sizeof(int);

    cout<<linearSearch(arr,n,key)<<endl;
 return 0;
}