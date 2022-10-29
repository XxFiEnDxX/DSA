#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    int i =0;
    int j =n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}