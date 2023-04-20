#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{  
    unordered_map<int,int> m;

    // m[1] = 10;
    // m[4] = 40;
    // m[3] = 30;
    // m[2] = 20;

    int count = 0;

    for(auto it = m.begin(); it != m.end(); it++){
        count++;
    }
    cout<<(m.empty());
    return 0;
}