#include<bits/stdc++.h>
using namespace std;
int LCS(string& str1, string& str2, int i, int j){
    if(i < 0 || j < 0)return 0;
    if(str1[i] == str2[j])return 1+LCS(str1,str2,i-1,j-1);
    return 0+max(LCS(str1,str2,i-1,j),LCS(str1,str2,i,j-1));
}

int main()
{
    string str1;cin>>str1;
    string str2;cin>>str2;
    int n = str1.length();
    int m = str2.length();

    cout<<LCS(str1,str2,n-1,m-1);
    return 0;
}