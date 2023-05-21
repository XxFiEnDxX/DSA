#include<iostream>
using namespace std;

int solution(string str,int n){
    if(n == 0){
        return 0;
    }

    int val = solution(str,n-1);
    int dig = str[n-1] - '0';

    return val*10 + dig;
}

int strToInt(string str,int n){
    if(n == 0){
        return 0;
    }
    char ch = str[n-1];
    int val = strToInt(str,n-1);
    switch (ch)
    {
    case '9':
        val += 9;
        break;
    case '8':
        val += 8;
        break;
    case '7':
        val += 7;
        break;
    case '6':
        val += 6;
        break;
    case '5':
        val += 5;
        break;
    case '4':
        val += 4;
        break;
    case '3':
        val += 3;
        break;
    case '2':
        val += 2;
        break;
    case '1':
        val += 1;
        break;
    case '0':
        val += 0;
        break;
    default:
        break;
    }
    if(str.length() != n){
        val *= 10;
    }
    return val;
}

int main()
{
    string str;
    cin>>str;
    int n = str.length();

    // cout<<strToInt(str,n);
    cout<<solution(str,n);

    return 0;
}