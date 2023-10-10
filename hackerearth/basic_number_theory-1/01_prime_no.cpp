#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<bool> prime(100001,true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i*i <= 100001; i++) {
         if (prime[i]) { 
            for (int j = i*i; j <= 100001; j += i)
                prime[j] = false;
        }
    }


    int t;
    cin >> t;
    while (t--) {
        int n;cin >> n;
        vector<int> arr(n);
        long long oneCnt = 0;

        int ele;
        for (int i = 0; i < n; i++) {
            cin>>ele;
            arr[i] = ele;
            if(ele == 1)++oneCnt;
        }

        long long primeCnt = 0;
        for (int i = 0; i < n; i++)
        {
            if(prime[arr[i]] == 1){
                primeCnt++;
            }
        }

        cout<<primeCnt*((oneCnt*(oneCnt-1))/2)<<endl;
    }
    return 0;
}