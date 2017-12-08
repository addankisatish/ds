#include <iostream>
using namespace std;

void reverse(char *start, char *end)
{
    char temp;
    while(start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseWords(char *str)
{
    char *word_begin = NULL;
    char *temp = str;

    while(*temp)
    {
        if((word_begin == NULL) && (*temp != ' '))
        {
            word_begin = temp;
        }
        if((word_begin != NULL) && ((*(temp + 1) == ' ') || (*(temp+1) == '\0')))
        {
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    }
    reverse(str, temp-1);
}

int main()
{
    char str[] = "Hi";
    char str1[] = "Reverse the words in a string";
    char str2[] = "";

    cout << str << endl;
    reverseWords(str);
    cout << str << endl;
    
    cout << str1 << endl;
    reverseWords(str1);
    cout << str1 << endl;

    cout << str2 << endl;
    reverseWords(str2);
    cout << str2 << endl;

    return 0;
}
