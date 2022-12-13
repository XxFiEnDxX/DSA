#include<iostream>
#include<cstring>
using namespace std;

class Fun{
    public:
        void operator()(string s){
            cout<<"Having fun with "<<s;
        }
};

int main()
{
    //Functor
    Fun f;
    f("c++");
    return 0;
}