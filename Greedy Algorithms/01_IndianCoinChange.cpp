#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int money;
    int coin[7] = {1,2,5,10,20,50,100};
    int n = 7;
    cin>>money;

    int ans = 0;
    while(money > 0){
        int idx = upper_bound(coin,coin+n,money)-1-coin;
        cout<<coin[idx]<<" ";
        money = money - coin[idx];
        ans++;
    }

    cout<<endl<<ans;

    return 0;
}