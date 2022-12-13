#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node(int d){
        data = 10;
    }
};
int main()
{
    int a = 5;
    int* b = &a;
    cout << *b<<endl;

    node x(10);
    // cout<<x.data<<endl;

    node* head = &x;
    cout<<(*head)->data<<endl;

    return 0;
}