#include<iostream>
#include <string.h>
using namespace std;

void remove_extra_spaces(char *str)
{
    int i = 0;
    int j = 0;

    while(str[i] != '\0')
    {
        if((str[i] == ' ') && (str[i-1] == ' '))
            i++;
        else
            str[j++] = str[i++]; 
    }
    str[j] = '\0';
}

void remove_leading(char *str, char *remove_str)
{
    // The  strspn() function calculates the length of the initial segment of s which consists 
    // entirely of characters in accept.
    int strip_len = strspn(str, remove_str);
    
    //
    // memmove - copy memory area
    // void *memmove(void *dest, const void *src, size_t n);
    // The  memmove()  function  copies  n bytes from memory area src to memory area dest.  The memory areas may
    // overlap: copying takes place as though the bytes in src are first copied into a temporary array that does
    // not overlap src or dest, and the bytes are then copied from the temporary array to dest.
    memmove(str, str + strip_len,  strlen(str + strip_len) + 1);
}

void remove_trailing(char *str, char *remove_str)
{
    char* end = str + strlen(str);
    char* ptr = end - 1;

    // char *strchr(const char *s, int c);
    // The strchr() function returns a pointer to the first occurrence of the character c in the string s.
    while((ptr >= str) && (strchr(remove_str, *ptr) != NULL))
    {
        ptr--;
    }

    ptr++;
    *ptr = 0;
}

int count_tokens(char *str, char *delim_str)
{
    char *ptr = str;
    int count = 0;

    if(ptr == NULL)
        return count;

    while (ptr != NULL)
    {
        // strpbrk - search a string for any of a set of characters
        // char *strpbrk(const char *s, const char *accept);
        // The  strpbrk()  function  locates  the  first  occurrence in the string s of 
        // any of the characters in the string accept.
        // The strpbrk() function returns a pointer to the character in s that matches  one  of  the  characters  in
        // accept, or NULL if no such character is found.
        ptr = ::strpbrk(ptr, delim_str);
        if(ptr)
        {
            count++;
            ptr++;
        }
    }
    return count + 1;
}

void printWords(char *str)
{
    char word[50];
    int j = 0;
    int i = 0;

    remove_extra_spaces(str);
    while(str[i] != '\0')
    {
        if(str[i] == ' ') 
        {
            word[j] = '\0';
            cout << word << endl;
            j = 0;
        }
        else
        {
            word[j++] = str[i];
        }
        i++;
    }
    word[j] = '\0';
    cout << word << endl;
}

int main()
{
    char str[50] = "This    is a    example.";
    cout << str << endl;
    printWords(str);

    char str1[50] = "Hello.";
    cout << str1 << endl;
    printWords(str1);

    char str2[50] = "  Hello Niru.      ";
    cout << str2 << endl;
    remove_leading(str2, " ");
    remove_trailing(str2, " ");
    cout << str2 << endl;

    char str3[20] = "Good morning!";
    cout << "The number of words in " << str3 << " are :" << count_tokens(str3, " ") << endl;

    return 0;
}
