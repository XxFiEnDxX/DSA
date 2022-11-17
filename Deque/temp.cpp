#include<iostream>
#include<stack>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[n];
	stack<int> st;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		while(!st.empty() && a[i]>a[st.top()]){
			st.pop();
		}
		if(!st.empty())
			cout<<i - st.top()<<" ";
		else
			cout<<i+1<<" ";
		st.push(i);
	}
	cout<<"END";
	return 0;
}