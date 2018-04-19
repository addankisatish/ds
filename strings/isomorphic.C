#include<iostream>
#include<string.h>
using namespace std;

#define MAX_CHARS 256
//
// Two strings are called isomorphic, if they have once to one mapping
// possible for every character of str1 to every character of str2.
// All the occurances of every character in str1 map to the same character
// in str2.
//

bool areIsomorphic(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();

    if(m != n)
        return false;

    // To mark the visited characters in str2
    bool marked[MAX_CHARS] = {false};

    int map[MAX_CHARS];
    memset(map, -1, sizeof(map));

    for(int i = 0; i < n; i++)
    {
        // Seen first time
        if(map[str1[i]] == -1)
        {
            // If the current character of str2 is already seen,
            // one to one mapping is not possible.
            if(marked[str2[i]] == true)
                return false;

            marked[str1[i]] = true;
            map[str1[i]] = str2[i];
        }
        else if(map[str1[i]] != str2[i])
        {
            return false;
        }
    } 

    return true;
}

int main()
{
    cout << areIsomorphic("aab", "xyz") << endl;
    cout << areIsomorphic("aab", "xxz") << endl;
    return 0;
}
