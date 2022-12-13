#include<iostream>
#include<vector>
using namespace std;

class heap{
    vector<int> v;
    public:
    heap(){
        v.push_back(-1);
    }
    void push(int d){
        v.push_back(d);
        int idx = v.size()-1;
        int parent = idx/2;
        while (idx>1 && v[idx] < v[parent])
        {
            swap(v[idx],v[parent]);
            idx = parent;
            parent = idx/2;
        }
    }

    bool empty(){
        return v.size() == 1;
    }

    void print(){
        for (int i = 1; i < v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        
    }
};

int main()
{
    heap h;

    int arr[10] = {10,2,11,12,7,4,9,8,5,1};
    int n = sizeof(arr)/sizeof(int);

    for (int i = 0; i < n; i++)
    {
        h.push(arr[i]);
    }
    h.print();
    return 0;
}
