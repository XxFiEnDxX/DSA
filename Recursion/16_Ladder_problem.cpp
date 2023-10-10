#include<iostream>
using namespace std;


// w(w-1)+w(n-2)
int f(int n,int k){
    if(n == 0){
        return 1;
    }
    else if(n < 0){
        return 0;
    }
    int ans = 0;
    for(int i = 1; i <= k; i++){
        ans += f(n-i,k);
    }
    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<f(n,k);
    return 0;
}