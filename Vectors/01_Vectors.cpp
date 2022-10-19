#include<iostream>
#include<vector>

using namespace std;
int main()
{
    vector<int> v;
    vector<int> b(5,10); //5 interger with value 10;
    vector<int> c(b.begin(),b.end());
    vector<int> d{1,2,3,4,5,6};

    for (int i = 0; i < c.size(); i++)
    {
        cout<<c[i]<<",";
    }
    cout<<endl;

    //Using iterators
    //vector<int>::iterator;
    for(vector<int>::iterator it = b.begin(); it < b.end(); it++){
        cout<<*it<<",";
    }

    cout<<endl;

    int n;
    cin>>n;
    

    //Taking Input
    for (int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        v.push_back(num); //Add element At the end
    }
    
    for (int x:v)
    {
        cout<<x<<",";
    }
    cout<<endl;

    //MEMORY
    cout<<v.size()<<endl; //Number of element in the vector
    cout<<v.capacity()<<endl; //number of element vector can hold currently
    cout<<v.max_size()<<endl; //Maximum capacity vector can have according  to the available memeory
    return 0;
}