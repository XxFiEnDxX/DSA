#include <iostream>
using namespace std;
int main()
{
    int x = 10;
    cout << &x<<endl;

    float y =10.5;
    cout<<&y<<endl;

    //it doesnot work for character variable because
    //of operator overloading of '<<'; 
    char ch = 'A';
    //Explicti Type casting from char* to void*
    cout<<(void *) &ch <<endl;
    return 0;
}