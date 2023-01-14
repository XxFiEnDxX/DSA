#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int largest=0;
    int len=0;

    char arr[1000];
    char Larr[100];
    int n;
    cin>>n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        cin.getline(arr,1000);
        // cout<<arr;
        len = strlen(arr);
        if (len>largest)
        {
            largest=len;
            strcpy(Larr,arr);
        }
        
    }
    cout<<Larr<<" and "<<largest<<endl;
    
    return 0;
}