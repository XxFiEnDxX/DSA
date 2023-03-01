#include <iostream>
using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class ListNode
{
public:
    int val;
    ListNode *next = NULL;
    ListNode(int d)
    {
        val = d;
        next = NULL;
    }
};

ListNode *insertAtTail(ListNode *head, int d)
{
    if (head == NULL)
    {
        head = new ListNode(d);
        return head;
    }
    ListNode *t = head;

    while (t->next != NULL)
    {
        t = t->next;
    }

    ListNode* n = new ListNode(d);
    t->next = n;
    // n->next = NULL;
    return head;
}

ListNode *oddEvenList(ListNode *head)
{
    // if(head == NULL){
    //     return NULL;
    // }
    ListNode *oddHead = NULL;
    ListNode *evenHead = NULL;
    ListNode *oddTail = NULL;
    ListNode *evenTail = NULL;

    ListNode *temp = head;
    ListNode *swap = NULL;
    while (temp != NULL)
    {

        if (temp->val % 2 == 0)
        {
            if (evenHead != NULL)
            {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
            else
            {
                evenHead = temp;
                evenTail = temp;
            }
        }
        else
        {
            if (oddHead != NULL)
            {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
            else
            {
                oddHead = temp;
                oddTail = temp;
            }
        }
        swap = temp->next;
        temp->next = NULL;
        temp = swap;
    }

    if (oddHead != NULL && oddTail != NULL)
    {
        oddTail->next = evenHead;
    }
    else
    {
        return evenHead;
    }
    return oddHead;
}

void print(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n, ele;
    cin >> n;

    ListNode *head = NULL;

    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        head = insertAtTail(head, ele);
    }

    // print(head);
    print(oddEvenList(head));

    return 0;
}