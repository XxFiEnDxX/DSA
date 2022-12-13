#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> m;

    m.insert(make_pair("Mango", 50));
    m.insert({"Apple", 40});
    m.insert({"Apple", 40});
    m.insert({"Apple", 40});

    m["Pineapple"] = 10;
    m["Litchi"] = 30;

    for (auto p : m)
    {
        cout << p.first << " : " << p.second << endl;
    }

    auto it = m.find("Mango");

    if (it != m.end())
    {
        cout << m["Mango"] << endl;
    }

    cout << m.count("Apple") << endl;

    return 0;
}