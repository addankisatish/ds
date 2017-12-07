#include<iostream>
using namespace std;

#define OUT 0
#define IN 1

int countWords(const char *str)
{
    int w_count = 0;
    int state = OUT;
    while(*str)
    {
        if((*str == ' ') || (*str == '\t') || (*str == '\n'))
        {
            state = OUT;
        }
        else if(state == OUT)
        {
            state = IN;
            w_count++;
        }
        str++;
    }
    return w_count;
} 

int main()
{
    char str[] = "This is to count words";
    char str1[] = "";
    char str2[] = "         This is        another                                                                                                                          example";

    cout << str << " : " << countWords(str) << endl;
    cout << str1 << " : " << countWords(str1) << endl;
    cout << str2 << " : " << countWords(str2) << endl;

    return 0;
}
