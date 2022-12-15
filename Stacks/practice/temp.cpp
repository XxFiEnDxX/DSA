#include<iostream>
#include<algorithm>
#include<stack>


using namespace std;
int main(){
    stack<char> st;
    string s = "amit";
    string temp = "";


    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
    }
    

    for (size_t i = 0; i < s.size(); i++)
    {
        temp+=st.top();
        st.pop();
    }
    
    
    cout<<temp;
}