#include<iostream>
using namespace std;

int binarySerach(int *arr,int s,int e,int key){
    if (s>e)
    {
        return -1;
    }

    int mid = (s+e)/2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] < key)
    {
        return binarySerach(arr,mid+1,e,key);
    }
    else if (arr[mid] > key)
    {
        return binarySerach(arr,s,mid-1,key);
    }   
}
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;

    int key = 11;

    cout<<binarySerach(arr,0,n-1,key);
    return 0;
}