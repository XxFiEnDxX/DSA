#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char ch[])
{
    int i = 0;
    int j = strlen(ch) - 1;
    while (i < j)
    {
        if (ch[i] == ch[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char ch[1000];
    cin.getline(ch,1000);
    cout<<isPalindrome(ch);
    return 0;
}