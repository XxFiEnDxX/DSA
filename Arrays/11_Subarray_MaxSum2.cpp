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

    // cout<<csum[]<<endl;
    csum[0] = 0;

    
			for (int z = 0; z <= elearr.length - 2; z++) {
				if (elearr[z] == 1) {
					for (int j = z + 1; j < elearr.length - 1; j++) {
						if (elearr[j] == 1) {
							for (int j2 = j + 1; j2 < elearr.length; j2++) {
								if (elearr[j2] == 1) {
									continue;
								} else {
									counter++;
								}
							}
						} else {
							break;
						}
					}
				}
			}

    for (int i = 1; i < n; i++)
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
    // cout << "Length of array-";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cumulatedSum(n, arr);
    return 0;
}