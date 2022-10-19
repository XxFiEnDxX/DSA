#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertathead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}
void insertattail(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *tep = new node(data);
    temp->next = tep;
    temp = temp->next;
}
int length(node *&head)
{
    node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
void insertatmiddle(node *&head, int data, int pos)
{
    if (pos == 1)
    {
        insertathead(head, data);
    }
    else if (pos > length(head))
    {
        insertattail(head, data);
    }
    else
    {
        node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        node *rt = new node(data);

        rt->next = temp->next;
        temp->next = rt;
    }
}
int findele(node *head, int key)
{

    int c = 0;
    while (head != NULL)
    {

        if (head->data == key)
        {
            cout << c << endl;
            ;
            break;
        }
        c++;
        head = head->next;
    }
}

node *findmid(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node *mergesort(node *a, node *b)
{

    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = mergesort(a->next, b);
    }
    else
    {
        c = b;
        c->next = mergesort(a, b->next);
    }
    return c;
}
node *merge(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *mid = findmid(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;
    a = merge(a);
    b = merge(b);
    node *temp = mergesort(a, b);
    return temp;
}
void deleteele(node *head, int pos)
{
    node *temp = head;
    if (pos == 1)
    {
        delete temp;
        head = head->next;
        return;
    }
    node *current = head;
    node *prev = NULL;
    int cnt = 1;
    while (cnt < pos)
    {
        prev = current;
        current = current->next;

        cnt++;
    }
    prev->next = current->next;
    delete current;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
int main()
{
    node *head = takeinput();
    // print(head);
    // insertathead(head, 45);
    // print(head);
    // insertattail(head, 78);
    // print(head);
    // deleteele(head, 3);
    // print(head);
    // insertatmiddle(head, 48, 4);
    // print(head);
    // findele(head, 4);
    // cout << findmid(head)->data << endl;

    
    print(head);
    merge(head);
    print(head);
}