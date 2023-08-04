#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
using namespace std;

#define m 4
#define n 4

class Node{
    public:
    char ch;
    unordered_map<char,Node*> child;
    string word;
    bool isTerminal;
    Node(char s){
        ch = s;
        isTerminal = false;
        word = "";
    }
};

class Tries{
public:
Node* root = new Node('\0');
    void addWord(string str){
        Node* temp = root;
        for (char ele : str)
        {
            if(temp->child.count(ele) == 0){
                temp->child[ele] = new Node(ele);
            }
            temp = temp->child[ele];
        }
        temp->isTerminal = true;
        temp->word = str;
    }
};

void dfs(char board[][4],int i, int j,Node* node,bool**visited,unordered_set<string> &s){
    // src check
    char ch = board[i][j];

    if(node->child.count(ch) == 0){
        return;
    }

    //found
    visited[i][j] == true;
    node = node->child[ch];
    if(node->isTerminal == true){
        s.insert(node->word);
    }

    // 8-direaction dfs

    // int dx[] = {0,1,1,1,0,-1,-1,-1};
    // int dy[] = {-1,-1,0,1,1,1,0,-1};

    // 4-direction 
    int dx[] = {1,0,-1,0};
    int dy[] = {0,-1,0,1};

    for (int k = 0; k < 4; k++)
    {
        int ni = dx[k] + i;
        int nj = dy[k] + j;

        if(ni >= 0 && nj >= 0 && ni < m && nj < n && !visited[ni][nj]){
            dfs(board,ni,nj,node,visited,s);
        }
    }
    visited[i][j] = false;
    
}

int main()
{
    string word[] = {"amit","car","cat","tree","bee","man","ice","nice","hen","hello"};

    char board[4][4] = {{'a','t','r','e'},
                        {'c','m','i','e'},
                        {'a','n','c','b'},
                        {'h','e','e','l'},};

    // 1 Implement Tries
    Tries T;
    for(string str:word){
        T.addWord(str);
    }

    //2 unorder_set to store words that are found.
    unordered_set<string> s;

    // 3 DFS for each given words
    bool **visited = new bool*[m];
    for (int i = 0; i < m; i++)
    {
        visited[i] = new bool[n]{false};
    }
    
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dfs(board,i,j,T.root,visited,s);
        }
    }

    // print the set
    for(auto ele:s){
        cout<<ele<<endl;
    }
    return 0;
}