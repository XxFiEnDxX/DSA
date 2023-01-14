#include<iostream>
using namespace std;
int main()
{
    string str ;
    // cin>> str;

    char arr[1000];
    cin.getline(arr,1000);
    cout<<arr<<endl;

    int i = 0;
    int j = i+1;

    while (arr[j] != '\0')
    {
        if(arr[i] == arr[j]){
            j++;
        }else{
            swap(arr[++i],arr[j++]);
        }
    }
    arr[i+1] = '\0';
    cout<<arr;

 return 0;
}