#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> d{1, 2, 3, 4, 5, 6};

    // Push the elemnt at the end of the vector o(1);
    d.push_back(7);

    // pop Out the last elemnt O(1);
    d.pop_back();

    // Insert at the middle of the error
    d.insert(d.begin() + 3, 100);

    // erase element  from the vector
    d.erase(d.begin() + 2);                // 3rd ele
    d.erase(d.begin() + 2, d.begin() + 5); // 2nd - 5th ele range

    // size
    cout << d.size() << endl;
    cout << d.capacity() << endl;

    // we avoid the shrink
    d.resize(8); // change the size the not the capacity of the vector
    cout << d.capacity() << endl;

    // remove all the element of the vector
    d.clear(); // size become zero but capacity will remain the same

    // Is empty
    if (d.empty()) // check vector is empty or not
    {
        cout << "vector is empty!" << endl;
    }

    d.push_back(11);
    d.push_back(12);
    d.push_back(13);
    cout << d.front() << endl;
    cout << d.back() << endl;

    // reserve
    int n;
    cin >> n;
    d.reserve(100);

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        d.push_back(num);
    }
    cout<<d.capacity()<<endl;

    // Print the vector
    for (auto x : d)
    {
        cout << x << ",";
    }
    return 0;
}