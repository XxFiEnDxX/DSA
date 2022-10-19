#include<iostream>
using namespace std;

void readline(char a[],int maxL){
    int i=0;
    char ch = cin.get();
    while (ch!='\n')    
    {
        a[i]=ch;
        i++;
        if (i==maxL-1){
            break;
        }
        ch = cin.get();
    }
    
    a[i]='\0';
    return;
}

int main()
{
    char a[100];
    cin.getline(a,100,'$');
    readline(a,1000);
    cout<<a<<endl;
    return 0;
}