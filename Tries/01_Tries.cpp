#include <iostream>
#include <unordered_map>
using namespace std;

class node
{
public:
    char val;
    unordered_map<char, node *> children;
    bool terminal;
    node(char w)
    {
        val = w;
        terminal = false;
    }
};

class Tries
{
    node *root;
    int cnt;

public:
    Tries()
    {
        root = new node('\0');
        cnt = 0;
    }

    void insert(char *w)
    {
        node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                node*n = new node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool find(char *w)
    {
        node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                return false;
            }
        }
        return temp->terminal;
    }
};

int main()
{
    Tries A;

    char str[][10] = {"no", "nope", "not", "noise", "apple", "app", "ape"};
    char input[] = "nope";

    for (int i = 0; i < 7; i++)
    {
        // cout<<str[i]<<" ";
        A.insert(str[i]);
    }

    // cin >> input;

    if (A.find(input))
    {
        cout << "Present!" << endl;
    }
    else
    {
        cout << "Not Present!" << endl;
    }

    return 0;
}