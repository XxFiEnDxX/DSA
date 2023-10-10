#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int cnt = 1;
    int Csum = 0;

    int left = 1;

    for (int i = 1; i <= n; i+=2)
    {
        Csum += i;
        // cout<<Csum<<" ";

        while(Csum > n){
            Csum -= left;
            left += 2;
        }
        if(Csum == n){
            cnt++;
            left = i+1;
            Csum = 0;
        }
    }

    cout<<cnt;
    
    return 0;
}