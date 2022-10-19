#include <iostream>
#include <list>

using namespace std;
int main()
{
    list<int> l;
    list<int> l1{1, 2, 10, 8, 5};
    list<string> l2{"apple", "guava", "mango"};

    l2.push_back("pineapple"); // insert-at-tail
    l2.push_front("kiwi");     // insert-at-tail

    l2.sort(); // Sorting
    l2.reverse(); // Reversing

    cout << l2.front() << endl;
    cout << l2.back() << endl;

    l2.pop_front();
    l2.pop_back();

    for (auto it = l2.begin(); it != l2.end(); it++)
    {
        cout<<(*it)<<"->";
    }
    
    cout<<endl;

    for (string s : l2)
    {
        cout << s << "->";
    }

    return 0;
}