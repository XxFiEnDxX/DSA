#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;

    int dif;

    int len = str.length();
    int i = 0;
    int j = 0;
    while (j < len-1)
    {
        dif = (str[i + 1]) - (str[i]);
        str.insert(++i, to_string(dif));
        for (int z = 0; z < to_string(abs(dif)).length(); z++)i++;
        j++;
    }

    for (int i = 0; i < str.length(); i++)cout << str[i];

    return 0;
}