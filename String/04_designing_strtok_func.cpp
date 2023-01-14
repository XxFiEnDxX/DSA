#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

char *mystrtok(char *s, char dlm)
{
    static char *input = NULL;

    if (s != NULL)
    {
        input = s;
    }

    // base case
    if (input == NULL)
    {
        return NULL;
    }

    char *output = new char[strlen(input) + 1];
    int i=0;
    for (; input[i] != '\0'; i++)
    {
        if (input[i] != dlm)
        {
            output[i] = input[i];
        }
        else
        {
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }

    // corner case
    output[i] = '\0';
    input = NULL;
    return output;
}

int main()
{
    char s[100] = "Today, is the rainy day";

    char *ptr = mystrtok(s, ' ');
    cout << ptr << endl;

    while (ptr != NULL)
    {
        ptr = mystrtok(NULL, ' ');
        cout << ptr << endl;
    }

    return 0;
}