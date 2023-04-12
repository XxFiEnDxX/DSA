#include<iostream>
#include<string.h>
using namespace std;

string find_window(string s, string pt){
    //1. lengths of strings
    int SL = s.length();
    int PL = pt.length();

    //2. corner case
    if (PL > SL)
    {
        return "None";
    }

    //3. freq
    int FS[256]={0};
    int FP[256]={0};
    for (int i = 0; i < PL; i++)
    {
        char ch = pt[i];
        FP[ch]++;
    }
    
    //4. Silding Window
    int cnt = 0;
    int start = 0;
    int min_len = INT32_MAX;
    int start_idx = -1;
    for (int i = 0; i < SL; i++)
    {
        char ch = s[i];
        FS[ch]++;

        //Maintain cnt for characters matched
        if (FP[ch] != 0 && FS[ch] <= FP[ch])
        {
            cnt++;
        }

        if (cnt == PL)
        {
            //Start contracting from left
            char temp = s[start];

            while (FP[temp] == 0 || FS[temp] > FP[temp])
            {
                FS[temp]--;
                start++;
                temp = s[start];
            }

            //Length of the window
            int window_len = i - start + 1;
            if (window_len < min_len)
            {
                min_len = window_len;
                start_idx = start;
            }   
        }
    }

    if (start_idx == -1)
    {
        return "None";
    }
    string ans = s.substr(start_idx,min_len);
    return ans;
}
  
int main()
{
    // string str = "hllloeaeo world";
    // string pattern = "eelo";
    string str,pattern;

    getline(cin,str);
    cin>>pattern;
    // cout<<str<<" "<<pattern<<"\n";

    cout<<find_window(str,pattern);
    return 0;
}