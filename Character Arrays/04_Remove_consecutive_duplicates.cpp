#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicates(char ch[])
{
    int curr=0;
    int prev=0;
    int len=strlen(ch);
    if (len==1 or len==0)
    {
        return;
    }
    for (int curr = 1; curr < len; curr++)
    {
        if (ch[curr]!= ch[prev])
        {
            prev++;
            ch[prev]=ch[curr];
        }
    }
    ch[prev+1]='\0';
    return;
}

int main()
{
    char ch[1000];
    cin.getline(ch,1000);
    removeDuplicates(ch);
    cout<<ch;
    return 0;
}