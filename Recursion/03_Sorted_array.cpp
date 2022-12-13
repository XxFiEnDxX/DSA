#include<iostream>
using namespace std;

bool sortCheck(int *arr,int n){
    if (n==0 or n==1)
    {
        return true;
    }

    if (arr[0] < arr[1] && sortCheck(arr+1,n-1))
    {
        return true;
    }
    
    return false;
    
    
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    // int arr[5] = {2,5,1,4,3};
    // int arr[5] = {1,2,3,4,99999999};
    cout<<sortCheck(arr,5);
    return 0;
}