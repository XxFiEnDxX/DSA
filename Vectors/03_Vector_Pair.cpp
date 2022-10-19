#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class car
{
public:
    int x, y;
    string car_name;
    car(string n, int a, int b)
    {
        car_name = n;
        x = a;
        y = b;
    }
    int distant(){
        return x*x + y*y;
    }
};

bool compare(car a , car b){
    int d1 = a.distant(); 
    int d2 = b.distant(); 
    if (d1 == d2)
    {
        return a.car_name.length() < b.car_name.length();
    }
    return d1 < d2; 
}

int
main()
{
    vector<car> v;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        string name;
        cin >> name >> x >> y;
        car temp(name,x,y);
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    for (auto i : v)
    {
        cout<<"Car "<<i.car_name<<" Dist "<<i.distant()<<" Location "<<i.x<<","<<i.y<<endl;
    }

    return 0;
}