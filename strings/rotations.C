#include<iostream>
#include <string.h>
using namespace std;

int areRotations(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if( len1 != len2)
        return 0;

    char *temp = new char[len1*2 + 1];
    strcpy(temp, str1);
    strcat(temp, str1);
    temp[len1*2] = '\0';

    cout << "The concatenated string is: " << temp << endl;

    //
    // Now check if str2 is substring of temp.
    //
    char *ptr = strstr(temp, str2);

    delete[] temp;
    
    return (ptr != NULL) ? 1 : 0;
} 

int main()
{
    char *str1 = "AACD";
    char *str2 = "ACDA";
    
    if(areRotations(str1, str2))
        cout << str1 << " " << str2 << " are rotations of each other." << endl;
    else
        cout << str1 << " " << str2 << " are rotations of each other." << endl;

    return 0;

}
