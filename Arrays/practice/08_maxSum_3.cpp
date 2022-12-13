// Kadane's Algorithm
// Time comp-> O(n)

#include <iostream>
#include <climits>
using namespace std;

void kadaneAlgo(int n, int arr[])
{
    int maxSum = INT_MIN;
    int curSum = 0;

    for (int i = 0; i < n; i++)
    {
        curSum += arr[i];

        if (curSum < 0)
        {
            curSum = 0;
        }
        if (curSum > maxSum)
        {
            maxSum = curSum;
        }
    }


    cout << "Max Sum is " << maxSum << endl;
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

    kadaneAlgo(n, arr);
    return 0;
}