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

// insertion

void insertAtHead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
    return;
}
void insertAtTail(node *&head, int d)
{
    if (head == NULL)
    {
        insertAtHead(head, d);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *n = new node(d);
    temp->next = n;
}
int length(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
void insertAtMiddle(node *&head, int d, int p)
{
    if (p == 0)
    {
        insertAtHead(head, d);
        return;
    }
    else if (p >= length(head))
    {
        insertAtTail(head, d);
    }
    else
    {
        node *temp = head;
        for (int i = 1; i < p; i++)
        {
            temp = temp->next;
        }
        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

// DELETION

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}
void deleteAtTail(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Searching

int search(node *head, int key)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        if (head->data == key)
        {
            return cnt;
        }
        head = head->next;
    }
    return 0;
}

void minMax(node *head)
{
    if (head == NULL)
    {
        cout << "List is empty!!" << endl;
        return;
    }

    int min = head->data;
    int max = head->data;
    while (head != NULL)
    {
        if (head->data > max)
        {
            max = head->data;
        }
        if (head->data < min)
        {
            min = head->data;
        }
        head = head->next;
    }
    cout << "MIN is " << min << endl;
    cout << "MAX is " << max << endl;
    return;
}

// for Inputing Outputing
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

void take_input(node *&head)
{
    int n, d;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        insertAtHead(head, d);
    }
    return;
}

// Mid-Point
node *midpoint(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// OPERATOR overloading (<<,>>)

istream &operator>>(istream &it, node *&head)
{
    take_input(head);
    return it;
}
ostream &operator<<(ostream &ot, node *head)
{
    print(head);
    return ot;
}

int main()
{
    node *head = NULL;
    node *head2 = NULL;

    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    print(head);

    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    print(head);

    insertAtMiddle(head, 0, 0);
    insertAtMiddle(head, 99, 4);
    insertAtMiddle(head, 7, 100);

    print(head);

    deleteAtHead(head);
    deleteAtTail(head);

    print(head);

    cout << "Your key is present at " << search(head, 99) << " place." << endl;

    cin >> head >> head2;
    cout << head << head2;

    minMax(head);
    minMax(head2);

    node *mid = midpoint(head);
    cout << mid->data;
    return 0;
}