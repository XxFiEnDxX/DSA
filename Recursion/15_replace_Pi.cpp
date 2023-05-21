#include<iostream>
using namespace std;
//Replace "pi" with "3.14" in a string
void solution(char* str, int i){
    if(str[i] == '\0' or str[i+1] == '\0'){
        return ;
    }
    if(str[i] == 'p' and str[i+1] == 'i'){
        int j = i+2;

        while (str[j] != '\0')
        {
            j++;
        }

        while (j >= i+2)
        {
            swap(str[j],str[j+2]);
            j--;
        }

        str[i] = '3';
        str[i+1] = '.';
        str[i+2] = '1';
        str[i+3] = '4';
        
        solution(str,i+4);
    }
    else{
        solution(str,i+1);
    }
    return;
}
int main()
{
    char str[100];
    cin>>str;
    solution(str,0);
    cout<<str;
    return 0;
}