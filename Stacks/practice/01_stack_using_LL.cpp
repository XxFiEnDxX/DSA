#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};


class Stack{
    public:
    node* head = NULL;
    int cnt = 0;
    Stack(){
        head = NULL;
    }

    void push(int d){
        if (head == NULL)
        {
            head = new node(d);
            cnt++;
        }else
        {
            node* n = new node(d);
            n->next = head;
            head = n;
            cnt++;
        } 
    }

    int pop(){
        if (cnt == 0)
        {
            return -1;
        }
        
        int temp = head->data;
        head = head->next;
        cnt--;
        return temp;
    }

    int top(){
        return head->data;
    }

    int size(){
        return cnt;
    }
    
    bool isEmpty(){
        if (cnt == 0)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    cout<<s1.size()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.size()<<endl;

    return 0;
}