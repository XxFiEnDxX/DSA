#include<iostream>
#include<set>
using namespace std;
int main()
{
    int arr[] = {10,20,30,40,11,25,6};
    int n = sizeof(arr)/sizeof(int);

    set<int> s;
    for (int i = 0; i < n; i++) 
    {
        s.insert(arr[i]);
    }
    s.erase(10);
    for (set<int>::iterator it = s.begin();it != s.end(); it++)
    {
        cout<<*(it)<<" ";
    }

    return 0;
}