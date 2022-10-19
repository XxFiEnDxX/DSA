//Kadane's Algorithm
//Time comp-> O(n)

#include <iostream>
#include<climits>
using namespace std;

void kadaneAlgo(int n, int arr[])
{
    int Max=INT_MIN;
    int Sum=0;

    int left=-1;
    int right=-1;

    //KADANE"S ALGO
    for (int i = 0; i < n; i++)
    {
        Sum+=arr[i];
        if (Sum<0)
        {
            Sum=0;
        }
        Max=max(Sum,Max);   
    }
    
    cout<<"Max Sum is "<<Max<<endl;
    
}

int main()
{
    int n;
    cout << "Length of array-";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    kadaneAlgo(n, arr);
    return 0;
}