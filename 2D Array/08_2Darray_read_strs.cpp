#include<iostream>
using namespace std;
int main()
{
    char a[100][100];

    int n ;
    cin>>n;
    cin.get();

    for (int i = 0; i < n; i++)
    {
        cin.getline(a[i], 100);
    }

    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
    
    
 return 0;
}