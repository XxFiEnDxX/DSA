#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    char ch;
    stack<char> stk;

    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i];

        if (ch == '(')
        {
            stk.push(ch);
        }
        else if (ch == ')')
        {
            stk.pop();
        }
    }

    if (stk.empty())
    {
        return 1;
    }

    return 0;
}

int main()
{
    string s = "{([])}e";

    cout << check(s);

    return 0;
}