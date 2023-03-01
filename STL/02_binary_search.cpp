#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);

    int key = 5; 
    
    bool present = binary_search(arr,arr+n,key);
    if (present)
    {
        cout<<"Present";
    }else
    {
        cout<<"Absent";
    }


    //lower bound method (log(n)) (ele >= key)
    auto it = lower_bound(arr,arr+n,key);
    cout<<endl<<"Lower bound of 5 is "<<(it-arr)<<endl;

    //upper bound method (ele > key)
    auto it1 = upper_bound(arr,arr+n,key);  //strictly greater than key
    cout<<endl<<"Upper bound of 5 is "<<(it1-arr)<<endl;
    
    cout<<"Frequency of 5 is "<<(it1-it)<<endl;
    return 0;
}