#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    list<int> l1;
    pair<int,int> mnmx;

    // int min,max;

    for (int i = 5; i >= 1; i--)
    {
        l1.push_front(i);
    }
    for (int i = 6; i <= 10; i++)
    {
        l1.push_front(i);
    }

    l1.reverse();

    l1.sort();

    // max = max_element(l1.front(),l1.end());

    mnmx = minmax(l1.begin(),l1.begin()+10);


    for (int x : l1)
    {
        cout << x << " ";

    }

    return 0;
}