#include <iostream>
#include<climits>
using namespace std;

void subarray(int n, int arr[])
{
    int Max=INT_MIN;
    int Sum=0;

    int left=-1;
    int right=-1;



    for (int i = 0; i < n; i++)
    {
        for (int k = i; k <n; k++)
        {
            Sum=0;
            for (int j = i; j <= k; j++)
            {
                Sum+=arr[j];
            }
            // Max=max(Max,Sum);
            if (Sum>Max)
            {
                Max=Sum;
                left=i;
                right=k;
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

    subarray(n, arr);
    return 0;
}