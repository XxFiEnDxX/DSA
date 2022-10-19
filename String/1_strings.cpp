#include <iostream>
#include <string>

using namespace std;
int main()
{
    // string Init
    string s0;
    string s1("Hello");

    string s2 = "Hellow World";
    string s3(s2);

    string s4 = s3;
    char a[] = {'a', 'b', 'c', '\0'};
    string s5(a);

    cout << s0 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;

    if (s0.empty())
    {
        cout << "s0 is an empty string"<<endl;
    }

    // Append
    s0.append("I love C++ ");
    cout << s0 << endl;
    // cout<< s5;
    s0 += " and Python";
    cout << s0 << endl;
    // cout << s0;
    cout<<s0.length()<<endl;
    s0.clear();
    cout<<s0.length()<<endl; 
    // cout << s0;

    s0 ="Apple";
    s1="Mango";
    cout<<s0.compare(s0)<<endl;

    if (s1>s0)
    {
        cout<<"Mango is greater"<<endl;
    }
    string s ="i love apple as it is dead";
    int idx = s.find("apple");
    cout<<idx<<endl;

    // string word ="apple";
    // int len = word.length();
    // s.erase(idx,len+1);
    // cout<<s<<endl;

    //Iterators
    for (auto it = s.begin(); it < s.end(); it++)
    {
        cout<<(*it)<<",";
    }
    
    //for each loop   -> only in c++11;
    cout<<endl;
    for(auto c:s1){
        cout<<c<<".";
    }
    
    
}