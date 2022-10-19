//Cumulated Sum
//time complex-> O(n^2)

#include <iostream>
#include<climits>
using namespace std;

void cumulatedSum(int n, int arr[])
{
    int Max=INT_MIN;
    int Sum=0;

    int csum[n]{0};

    int left=-1;
    int right=-1;

    for (int i = 0; i < n; i++)
    {
        csum[i]=csum[i-1]+arr[i];
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j <n; j++)
        {
            Sum=csum[j]-csum[i-1];
            // Max=max(Max,Sum);
            if (Sum>Max)
            {
                Max=Sum;
                left=i;
                right=j;
            }
            
        }
    }
    cout<<"Max Sum is "<<Max<<endl;
    for (int z = left; z <= right; z++)
    {
        cout<<arr[z]<<" ";
    }
    
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

    cumulatedSum(n, arr);
    return 0;
}