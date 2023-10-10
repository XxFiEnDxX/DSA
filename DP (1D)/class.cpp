#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Student
{
    public:
    int id;
    string name;
    char gender;
};

void Selection_sort(vector<Student*>&arr)
{
    int noCom = 0;
    int noSwap = 0;
    int n = arr.size();
    int MinI;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        MinI = i;
        for (int j = i; j <= n - 1; j++)
        {
            ++noCom;
            if (arr[j]->id < arr[MinI]->id)
            {
                MinI = j;
            }
        }
        if(MinI != i){
            swap(arr[i],arr[MinI]);
            ++noSwap;
        }
    }
    cout<<"No. of compares - "<<noCom<<endl;
    cout<<"No. of Swaps - "<<noSwap<<endl;
}

void Bubble_sort(vector<Student*> &arr){
    int n = arr.size();
    int noCom = 0;
    int noSwap = 0;
    for (int i = 1; i <= n-1; i++)//i{1 to n-1}
    {
        for (int j = 0; j < n-i; j++)//j{0  to n-i}
        {
            ++noCom;
            if (arr[j]->id > arr[j+1]->id)
            {
                ++noSwap;
                swap(arr[j],arr[j+1]);
            }
        } 
    }

    cout<<"No. of compares - "<<noCom<<endl;
    cout<<"No. of Swaps - "<<noSwap<<endl;
}

void Insertion_sort(vector<Student*> &arr)
{
    int noCom = 0;
    int noSwap = 0;
    int n = arr.size();
    for (int i = 1; i <= n - 1; i++)
    {
        Student* e = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j]->id > e->id)
        {
            ++noCom;
            ++noSwap;
            arr[j + 1] = arr[j];
            j -= 1;
        }
        ++noSwap;
        arr[j + 1] = e;
    }
    cout<<"No. of compares - "<<noCom<<endl;
    cout<<"No. of Swaps - "<<noSwap<<endl;
}

void print(vector<Student*>&arr){
    cout<<endl<<"Sorted"<<endl;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]->id<<" ";
        cout<<arr[i]->name<<" ";
        cout<<arr[i]->gender<<" ";
        cout<<endl;
    }
}


int main()
{
    // Student arr[10];
    vector<Student*> arr;

    for (int i = 0; i < 10; i++)
    {
        Student* temp = new Student();

        cin>>temp->id;
        cin>>temp->name;
        cin>>temp->gender;

        arr.push_back(temp);
    }

    cout<<"Unsorted"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]->id<<" ";
        cout<<arr[i]->name<<" ";
        cout<<arr[i]->gender<<" ";
        cout<<endl;
    }

    // Bubble_sort(arr);
    Insertion_sort(arr);
    // Selection_sort(arr);
    
    cout<<endl<<"Sorted"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]->id<<" ";
        cout<<arr[i]->name<<" ";
        cout<<arr[i]->gender<<" ";
        cout<<endl;
    }

    
    
    return 0;
}