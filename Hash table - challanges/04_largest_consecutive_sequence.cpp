#include<iostream>
#include<unordered_map>
using namespace std;

int largestConsecutiveSequence(int arr[],int n){
    int lar = 0;
    int no;
    unordered_map<int,int> m;

    for (int i = 0; i < n; i++)
    {
        no = arr[i];

        if (m.count(no-1) == 0 && m.count(no+1) == 0)
        {
            m[no] = 1;
        }
        else if(m.count(no-1) != 0 && m.count(no+1) != 0){
            int l = m[no-1];
            int r = m[no+1];

            int size = l+1+r;
            m[no-m[no-1]] = size;
            m[no+m[no+1]] = size;
        }
        else if(m.count(no-1) != 0 && m.count(no+1) == 0)
        {
            int l = m[no-1];
            
            m[no-m[no-1]] = l+1;
            m[no] = l+1;
        }
        else{
            int l = m[no+1];
            
            m[no+m[no+1]] = l+1;
            m[no] = l+1;

        }
        
    }

    for (auto x : m)
    {
        lar = max(lar,x.second);
    }
    
    return lar;
}

int main()
{
    int arr[14]={1,2,3,4,6,7,8,9,10,12,13,14,15,5};
    int n = 14;

    cout<<largestConsecutiveSequence(arr,n);
    return 0;
}