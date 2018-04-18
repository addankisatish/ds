#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

void swap(char *a, char *b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

//
// Input paramters: 
// string, start index of the string, end index of the string.
//
void permute(char *str, int start, int end)
{
    if(start == end)
        cout << str << endl;
    else
    {
        for(int i = start; i <=end; i++)
        {
            swap((str + start), (str + i));
            permute(str, start+1, end);
            swap((str + start), (str + i)); 
        }
    }
}

void permute1(string str, string out)
{
    //
    // when the size of str becomes 0, out has the permutation.
    //
    if(str.size() == 0)
    {
        cout << out << endl;
        return ;
    }

    for(int i = 0; i < str.size(); i++)
    {
        // Remove the first character from str and add it to out.
        permute1(str.substr(1), out + str[0]);
        
        // Rotate the string in such a way the seond character moves to beginning.
        rotate(str.begin(), str.begin() + 1, str.end());  
    } 
}

int main()
{
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);

    cout << endl << endl;

    string str1 = "ABC";
    permute1(str1, "");
    
    return 0;
    
}
