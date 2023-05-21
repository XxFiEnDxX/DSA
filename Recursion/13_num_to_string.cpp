#include<iostream>
using namespace std;

string numTostr(int n){
    if(n == 0){
        return "";
    }
    string str = "";
    int dig = n%10;
    str += numTostr(n/10);

    switch (dig)
    {
    case 9:
        str += "nine ";
        break;
    case 8:
        str += "eight ";
        break;
    case 7:
        str += "seven ";
        break;
    case 6:
        str += "six ";
        break;
    case 5:
        str += "five ";
        break;
    case 4:
        str += "four ";
        break;
    case 3:
        str += "three ";
        break;
    case 2:
        str += "two ";
        break;
    case 1:
        str += "one ";
        break;
    case 0:
        str += "zero ";
        break;
    default:
        break;
    }
    return str;
}

int main()
{
    int n;
    cin>>n;

    cout<<numTostr(n);
    return 0;
}