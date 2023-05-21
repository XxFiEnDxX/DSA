#include <iostream>
using namespace std;

int myAtoi(string s)
{
    if (s == "")
    {
        return 0;
    }

    char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int n = s.length();
    char dig = s[n - 1];
    s[n - 1] = '\0';
    int ans = myAtoi(s[0][1]);

    if (dig == '-')
    {
        ans = ans * -1;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (dig == arr[i])
            {
                ans = (ans * 10) + i;
            }
        }
    }
    return ans;
}

int main()
{
    string s;
    getline(cin, s);
    // s[2] = '\0';
    // cout<<s<<endl;
    // cout<<s.length();

    cout << myAtoi(s);
    return 0;
}