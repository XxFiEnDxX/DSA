#include<iostream>
using namespace std;
int main()
{

    //it is important to end character array with '\0' null character;
    char arr[]={'h','e','l','l','o','\0'};
    char hye[]="hello";

    cout<<arr<<" Its size is "<< sizeof(arr)<<endl;
    cout<<hye<<" Its size is "<< sizeof(hye)<<endl;
    return 0; 
}