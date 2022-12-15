#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // forward_list<int> head;
    list<int> head;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        head.push_back(d);
    }

    head.sort();
    list<int>::iterator ele = head.begin();
    
    // head.remove(3);

    for (int i = 1; i < 4; i++)
    {
        ele++;
    }
    

    head.erase(ele);
    

    for (list<int>::iterator i = head.begin(); i != head.end(); i++)
    {
        cout<<*i<<"->";
    }
    
    return 0;
}