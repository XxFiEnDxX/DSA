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

void insertAtHead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }

    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

node *build()
{
    int ele;
    cin >> ele;

    node *head = NULL;

    while (ele != -1)
    {
        insertAtHead(head, ele);
        cin >> ele;
    }
    return head;
}

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

istream &operator>>(istream &ip, node *&head)
{
    head = build();
    return ip;
}

ostream &operator<<(ostream &op, node *head)
{
    printLL(head);
    return op;
}

node *midPoint(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *kthNode(node *head, int j)
{
    node *slow = head;
    node *fast = head;
    for (int i = 0; i < j; i++)
    {
        if (fast == NULL)
        {
            return new node(-1);
        }
        else
        {
            fast = fast->next;
        }
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{
    node *head;
    node *mid;
    cin >> head;
    cout << head;

    mid = kthNode(head, 3);

    cout << mid->data;
    return 0;
}