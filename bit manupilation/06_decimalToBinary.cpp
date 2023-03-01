#include <iostream>
using namespace std;
int decimalToBinary(int n)
{
    int ans = 0;
    int p = 1;
    while (n != 0)
    {
        int last_bit = (n & 1);
        ans += last_bit * p;

        p = p * 10;
        n = n >> 1;
    }
    return ans;
}

int decimalToBinary2(int n)
{
    int ans = 0;
    int p = 1;
    while (n != 0)
    {
        if (n % 2 != 0)
        {
            ans += 1 * p;
        }
        else
        {
            ans += 0 * p;
        }
        n = n/2;
        p = p * 10;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;

    cout << decimalToBinary(n) << endl;
    cout << decimalToBinary2(n) << endl;
    return 0;
}