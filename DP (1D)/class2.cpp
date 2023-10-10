#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int>&arr){
    int i = 0;
    int j = arr.size()-1;
    while(i < j){
        
    }

}

void Insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i <= n - 1; i++)
    {
        int e = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j] > e)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = e;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {5,4,3,6,1,2,8,7,9,10};

    Insertion_sort(arr);
    
    return 0;
}