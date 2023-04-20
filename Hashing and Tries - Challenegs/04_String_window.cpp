#include<iostream>
using namespace std;

string sliding_window(string str,string ptr){
    
    int str_len = str.length();
    int ptr_len = ptr.length();

    // freq holder
    int freq_str[256]{0};
    int freq_pat[256]{0};

    // corner case
    if (ptr_len>str_len)
    {
        return "No String";
    }
    
    // build pattern freq
    for (int i = 0; ptr[i] != '\0'; i++)
    {
        freq_pat[ptr[i]]++;
    }

    // Silding window
    int cnt = 0;
    int start = 0;
    int start_idx = -1;
    int min_size = INT32_MAX;
    int cur_size = 0;
    for (int i = 0; str[i]!='\0'; i++)
    {
        char ch = str[i];
        freq_str[ch]++;

        // Counter
        if(freq_pat[ch] != 0 && freq_str[ch] <= freq_pat[ch]){
            cnt++;
        }

        if (cnt == ptr_len)
        {
            // shrink
            char temp = str[start];
            while (freq_pat[temp] == 0 || freq_str[temp] > freq_pat[temp])
            {
                freq_str[temp]--;
                start++;
                temp = str[start];
            }
            
            cur_size = i - start + 1;
            if (cur_size < min_size)
            {
                min_size = cur_size;
                start_idx = start;
            }
            
            
        }

        
    }
    if (start_idx == -1)
    {
        return "No String";
    }
    return str.substr(start_idx,min_size);
}

int main()
{
    string str;
    string ptr;

    getline(cin,str);
    cin>>ptr;

    cout<<sliding_window(str,ptr);

    return 0;
}