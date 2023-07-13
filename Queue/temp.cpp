#include<iostream>
#include<vector>
using namespace std;
int main()
{
    cout<<"output-"<<endl;
    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    string path(v.begin(),v.end());
    cout<<path;
    string a = "ababz";
    string b = "";
    string c = "";
    cout<<min(a,b)<<endl;
    // cout<<(a == b)<<endl;
    // cout<<(b < a)<<endl;
    // cout<<(a < b)<<endl;
    // cout<<(a < c)<<endl;
    // cout<<("a"s < "a"s)<<endl;
    // cout<<("b"s < "a"s)<<endl;
    // cout<<("a"s < "b"s)<<endl;

    return 0;
}