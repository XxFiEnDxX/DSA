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
        cout << (*it) << "->";
    }
    cout << endl;
    for (string s : l2)
    {
        cout << s << "->";
    }
    cout << endl;

    l2.push_back("orange");
    l2.push_back("guava");
    l2.push_back("lichi");

    // remove a fruit
    string f;
    cin >> f;
    l2.remove(f); // remove all occurrence

    for (string s : l2)
    {
        cout << s << "->";
    }
    cout << endl;

    // erase elements;
    auto it = l2.begin();
    it++;

    l2.erase(it);

    for (string s : l2)
    {
        cout << s << "->";
    }
    cout << endl;

    auto it1 = l2.begin();
    it1++;
    l2.insert(it1, "strawberry");

    for (string s : l2)
    {
        cout << s << "->";
    }
    cout << endl;
    return 0;
}