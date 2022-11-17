

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

// INSERTING NODES =>
void insertAtTail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}

// TAKING INPUTS =>
node *take_Input()
{
    node *head = NULL;
    int d = 0;
    cin >> d;
    while (d != -1)
    {
        insertAtTail(head, d);
        cin >> d;
    }
    return head;
}





node* nthEleFromLast(node*head,int k){
    node*slow = head;
    node*fast = head;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    node *head = take_Input();
    int k;
    cin>>k;

    cout<<nthEleFromLast(head,k)->data;
    return 0;
}