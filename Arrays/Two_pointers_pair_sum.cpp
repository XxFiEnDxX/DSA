//Given a sorted array, find pair of elemnt that sum to K(Given)
// (1,3,5,7,10,11,12,13)

//Two pointer Approach

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter The Length of array:- ";
    cin>>n;

    int arr[n]{0};
    cout<<"Enter the array:- "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int sum;
    cout<<"Enter the sum :- ";
    cin>>sum;

    // int arr[]={1,3,5,7,10,11,12,13};
    // int sum=16;

    int i=0;
    int j=sizeof(arr)/sizeof(int)-1;
    while (i<j)
    {
        int Csum=arr[i]+arr[j];
        if (Csum<sum)   
        {
            i++;
        }
        if (Csum>sum)
        {
            j--;
        }
        if (Csum==sum)
        {
            cout<<arr[i]<<" and "<<arr[j]<<endl;
            i++;
            j--;
        } 
    }
    return 0;
}