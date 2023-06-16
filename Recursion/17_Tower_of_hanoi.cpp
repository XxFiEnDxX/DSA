#include<iostream>
using namespace std;

void move(int n, char src, char helper, char dest){
    if(n == 0){ // base case
        return ;
    }

    // move n-1 disks from src to helper
    move(n-1,src,dest,helper);

    // move the nth disk from src to dest
    cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;

    // move the n-1 disks from helper to dest
    move(n-1,helper,src,dest);
}

int main()
{
    ios_base::sync_with_stdio(false); // faster input/output
    cin.tie(NULL);

    int n;
    cin>>n;

    move(n,'A','B','C');
    return 0;
}