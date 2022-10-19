#include<iostream>
using namespace std;
int main()
{
    //pointer store the address of another variable
    int x = 10;


    int *ptr = &x; //declare plus intialise
    int **xptr = &ptr;  //double ptr'
    cout<<ptr<<" of "<<*ptr<<endl;
    cout<<xptr<<" of "<<*xptr<<endl;

    int *ptr1;  //it will store a garbage value.
    cout<<ptr1<<" garbage of "<<*ptr1<<endl;

    int *ptr2 = 0;
    return 0;
}