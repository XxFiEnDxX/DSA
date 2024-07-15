#include<bits/stdc++.h>
using namespace std;

class segment_tree{
    int N = 1e5+2;
    int* t;
    public:
    segment_tree(int n){
        N = n;
        t = new int[N*4];
    }

    void build(int *arr, int v, int tl, int tr){
        if(tl == tr){
            t[v] = arr[tl]; 
        }
        else{
            int tm = (tl+tr)/2;
            build(arr,v*2,tl,tm);
            build(arr,v*2+1,tm+1,tr);
            t[v] = t[v*2]+t[v*2+1];
        }
    }

    int query(int v, int tl, int tr, int l, int r){
        if(l > r){
            return 0;
        }
        if(l == tl && r == tr)return t[v];
        int tm = (tl+tr)/2;
        return query(v*2, tl, tm, l, min(r,tm))
                +query(v*2+1, tm+1, tr, max(l,tm+1), r);
    }

    void update(int v, int tl, int tr, int val, int pos){
        if(tl == tr){
            t[v] = val;
        }
        else{
            int tm = (tl+tr)/2;
            if(pos <= tm){
                update(v*2,tl,tm,val,pos);
            }else{
                update(v*2+1,tm+1,tr,val,pos);
            }
        t[v] = t[2*v]+t[2*v+1];
        }
    }
};

int main()
{
    int n;cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)cin>>arr[i];

    segment_tree*st = new segment_tree(n);
    st->build(arr,1,0,n-1);
    // st->display();
    cout<<st->query(1,0,n-1,0,0)<<endl;
    st->update(1,0,n-1,10,0);
    cout<<st->query(1,0,n-1,0,0)<<endl;




    
    return 0;
}