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

void insertAtHead(node *&head,node *&temp, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
    if (temp == NULL)
    {
        temp = head;
    }
    
}

void changeHead(node *head, node *temp);

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    int n, d, k, cnt = 0;
    node *head = NULL;
    node *temp = NULL;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> d;
        insertAtHead(head,temp, d);
        cnt++;
        if (cnt == k)
        {
            // changeHead()
        }
    }
    print(temp);
    return 0;
}