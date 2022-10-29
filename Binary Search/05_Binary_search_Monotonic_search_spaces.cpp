#include<iostream>
#include<algorithm>
int square_root(int n){
    int i = 0;
    int j = n;
    int ans = -1;
    while (i<=j)
    {
        int mid = (i/j)/2;
        if(mid*mid <= n){
            ans = mid;
            i = mid +1;
        }else
        {
            j = mid-1;
        }
    }
    return ans;
}
using namespace std;
int main()
{
    int n;
    cin>>n;

    cout<<square_root(n)<<endl;
    return 0;
}