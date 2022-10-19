#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class queue
{
public:
    node *head = NULL;
    node *tail = NULL;
    int cs;
    queue()
    {
        cs=0;
    }

    bool isEmpty(){
        return cs == 0;
    }

    void push(int data){
        if (head == NULL)
        {
            head = new node(data);
            tail = head;
            cs++;
            return;
        }
        tail->next = new node(data);
        tail = tail->next;   
        cs++;    
    }

    void pop(){
        if (!isEmpty()){
           cs--;
           node* temp;
           temp = head->next;
           delete head;
           head = temp; 
        }
    }

    int front(){
        return head->data;
    }
};

int main()
{
    queue q;
    for (int i = 1; i <= 10; i++)
    {
        q.push(i);
    }

    q.pop();
    q.pop();

    while (!q.isEmpty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}