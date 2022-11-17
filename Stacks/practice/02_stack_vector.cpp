#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class stack{
    vector<T> v;
    public:
    T size(){
        return v.size();
    }
    bool isempty(){
        if (v.size()==0)
        {
            return 1;
        }
        return 0;
    }
    void push(T d){
        v.push_back(d);
    }
    void pop(){
        v.pop_back();
    }
    T top(){
        if (isempty())
        {
            return -1;
        }else{
            return v[v.size()-1];
        }
        
    }
};
int main()
{
    stack<int> s;
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    cout<<s.size();
    s.pop();
    cout<<s.size();
    return 0;
}