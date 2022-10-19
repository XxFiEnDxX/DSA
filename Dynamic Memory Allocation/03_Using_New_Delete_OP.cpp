#include<iostream>
using namespace std;
int main()
{
    //Static Allocation;
    //Allocation + Deallocation = Compiler
    int arr[100];
    cout<<sizeof(arr)<<endl;
    cout<<arr<<endl;//symbol table
                    //here b cant be Overwritten
                    //b is a part of Read only Memory

    //Dynamic Allocation (on the fly);
    int n;
    cin>>n;
    int *a = new int[n];
    cout<<sizeof(a)<<endl;
    cout<<a<<endl;  //variable a that is creates 
                    //inside the static memory
                    //->Can be Overwritten
                    //a = new char[30];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    

    //Free up space
    delete [] a;
    
    return 0;
}