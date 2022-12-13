#include<iostream>
#include<climits>
using namespace std;

void check(int &n,int arr[])
{
    int Max=INT_MIN; 
    int Min=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>Max){   
            Max=arr[i];}   
        if (arr[i]<Min){   
            Min=arr[i];}

        // Max=max(Max,arr[i]);
        // Min=min(Min,arr[i]);
    }
    cout<<"Max value-"<<Max<<endl;
    cout<<"Min value-"<<Min<<endl;
}

int main()
{
    int n,key;
    cout<<"Length of array-";
    cin>>n;

    int arr[n]{0};
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    check(n,arr);
    
    return 0;
}