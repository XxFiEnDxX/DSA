#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string str1,str2,res;
        cin>>str1>>str2;

        int n = str1.length();

        for (int i = 0; i < n; i++)
        {
            if (str1[i] != str2[i])
            {
                res+='1';
            }else{
                res+='0';
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout<<res[i];
        }
        cout<<endl;
    }
    
    return 0;
}