#include<iostream>
#include<vector>
using namespace std;

void f(int i, vector<int> subs, vector<int> arr){
    if(i >= arr.size()){
        for(int i = 0; i < subs.size(); i++){
            cout<<subs[i]<<" ";
        }
        cout<<endl;
        return;
    }

    subs.push_back(arr[i]);
    f(i+1,subs,arr);
    subs.pop_back();
    f(i+1,subs,arr); 
}

int main()
{  
    vector<int> arr{1,2,3};
    vector<int> temp;
    f(0,temp,arr);
    return 0;
}