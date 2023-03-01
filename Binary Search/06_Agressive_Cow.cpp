#include <iostream>
#include <vector>
using namespace std;

bool checkMinDistance(vector<int> arr, int cow, int n, int min_sep)
{
    int last_cow = arr[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - last_cow >= min_sep)
        {
            last_cow = arr[i];
            cnt++;
            if (cnt == cow)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, t, c;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;

        int ele, ans = 0;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            cin >> ele;

            arr.push_back(ele);
        }

        // for (int i = 0; i < n; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }

        int s = 0;
        int e = arr[n - 1] - arr[0];

        // lastCow = arr[0];

        while (s <= e)
        {
            int mid = (s + e) / 2;

            bool checkMinSep = checkMinDistance(arr, c, n, mid);

            if (checkMinSep)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
            cout << ans << endl;
    }
    return 0;
}
