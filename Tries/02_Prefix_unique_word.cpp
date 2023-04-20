#include <iostream>
#include <unordered_map>
using namespace std;

class node
{
public:
    char val;
    unordered_map<char, node *> children;
    bool terminal;
    int freq = 0;
    node(char w)
    {
        if (w != '\0')
        {
            freq = 1;
        }
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
                temp->freq++;
            }
            else
            {
                node *n = new node(ch);
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
                // cout<<temp->val<<" : "<<temp->freq<<endl;
            }
            else
            {
                return false;
            }
        }
        return temp->terminal;
    }

    string uniquePrefix(char *w)
    {
        node *temp = root;
        string str = "";
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children[ch]->freq == 1)
            {
                str += ch;
                return str;
            }
            str += ch;
            temp = temp->children[ch];
        }
        return "-1";
    }
};

int main()
{
    Tries A;

    char str[][10] = {"no", "nope", "not", "noise", "apple", "app", "ape"};
    // char str[][10] = {"cobra","dog","dove","duck"};
    char input[] = "dog";
    int n = 7;
    for (int i = 0; i < n; i++)
    {
        // cout<<str[i]<<" ";
        A.insert(str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        // cout<<str[i]<<" ";
        cout<<A.uniquePrefix(str[i])<<" ";
    }

    // if (A.find(input))
    // {
    //     cout << "Present!" << endl;
    // }
    // else
    // {
    //     cout << "Not Present!" << endl;
    // }

    return 0;
}