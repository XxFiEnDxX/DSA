#include<iostream>
#include<algorithm> //STL
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);
    int key = 8;

    bool present = binary_search(arr,arr+n,key);
    if (present)
    {
        cout<<"present !"<<endl;
    }else
    {
        cout<<"Not present !"<<endl;
    }
    
    int *lb = lower_bound(arr,arr+n,key);

    cout<<"and the index is "<<lb-arr<<endl;
    
    return 0;
}