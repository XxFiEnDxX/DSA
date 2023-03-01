#include<iostream>
using namespace std;
int main()
{
    pair<int,char> p1;
    p1 = {10,'a'};
    // p1.first = 10;
    // p1.second = 'a';

    pair<int,char> p2(p1);
    cout<<p2.first<<endl;
    cout<<p2.second<<endl;

    int a = 100;
    string b = "Audi";
    pair<int,string> p3 = make_pair(a,b);
    cout<<p3.first<<" "<<p3.second<<endl;

    //pair of pair
    pair<pair<int,int>,string> car;
    car.second = "lambo";
    car.first.first = 10;
    car.first.second = 20;

    cout<<car.first.first<<endl;
    cout<<car.first.second<<endl;
    cout<<car.second<<endl;
    return 0;
}