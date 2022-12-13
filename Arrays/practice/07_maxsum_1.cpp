//Cumulated Sum
//time complex-> O(n^2)

#include <iostream>
#include<climits>
using namespace std;

void cumulatedSum(int n, int arr[])
{
    int maxSum = INT32_MIN,CurSum = 0;
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            CurSum = 0;
            for (int k = i; k <= j; k++)
            {
                CurSum += arr[k];
            }
            if (CurSum > maxSum)
            {
                maxSum = CurSum;
            }
            
            
        }
        
    }


    cout<<maxSum;
    
    
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cumulatedSum(n, arr);
    return 0;
}