#include<iostream>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    node(){
        left = NULL;
        right = NULL;
    }
};

class Tries{
    node* root = new node();
    public:

    void insert(int val){
        int bit;
        node* temp = root;
        for (int i = 31; i >=0; i--)
        {
            bit = (val>>i)&1;
            if (bit == 0)
            {
                if (temp->left == NULL)
                {
                    node* n = new node();
                    temp->left = n;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    node* n = new node();
                    temp->right = n;
                }
                temp = temp->right;
            }  
        }
    }

    int max_xor_helper(int val){
        node* temp = root;
        int bit;
        int ans = 0;
        for (int i = 31; i >=0; i--)
        {
            bit = (val>>i)&1;
            if (bit == 0)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    ans += (1<<i);
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    ans += (1<<i);
                }
                else
                {
                    temp = temp->right;
                }    
            }   
        }
        return ans;
    }

    int max_xor(int *arr,int n){
        int val;
        int ans = 0;
        int cur_max = 0;
        for (int i = 0; i < n; i++)
        {
            val  = arr[i];
            insert(val);
            cur_max = max_xor_helper(val);
            cout<<cur_max<<" ";
            ans = max(cur_max,ans);
        }
        return ans;
    }
};

int main()
{
    int n,temp=0;
    int arr[100];

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int c_arr[100];
    for (int i = 0; i < n; i++)
    {
        temp += arr[i];
        c_arr[i] = temp;
    }
    
    Tries t;
    cout<<t.max_xor(c_arr,n);
    return 0;
}