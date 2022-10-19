#include <iostream>
#include <stack>
using namespace std;

bool isValidExp(char *cha)
{
    stack<char> s;
    for (int i = 0; cha[i] != '\0'; i++)
    {
        char ch = cha[i];
        if (ch == '(')
        {
            s.push(ch);
            ;
        }
        else if (ch == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    char s[100] = "(()())";
    if (isValidExp(s))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}