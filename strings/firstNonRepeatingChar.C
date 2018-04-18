#include<iostream>
#include<limits.h>
using namespace std;

#define NO_OF_CHARS 256

struct countIndex
{
    int count;
    int index;
};

countIndex *getCountArray(char *str)
{
    countIndex *count = new countIndex[NO_OF_CHARS];
    for(int i = 0; str[i] != '\0'; i++)
    {
        count[str[i]].count++;
        if(count[str[i]].count == 1)
            count[str[i]].index = i;
    }
    return count;
}

int firstNonRepeating(char *str)
{
    countIndex *count = getCountArray(str);
    int result = INT_MAX;
    for(int i = 0; i < NO_OF_CHARS; i++)
    {
        if(count[i].count == 1 && result > count[i].index)
            result = count[i].index;
    }

    delete[] count;
    return result;
}

int main()
{
   char str[] = "geeksforgeeks";
   int index = firstNonRepeating(str);

   if(index == INT_MAX)
       cout << "All the characters are repeating or string is empty." << endl;
   else
       cout << "The first non-repeating character is: " << str[index] << endl;

   return 0;
}
