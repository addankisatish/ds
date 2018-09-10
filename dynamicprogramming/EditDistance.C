#include<iostream>
using namespace std;

int min(int a, int b, int c)
{
    int temp = ( a < b ) ? a : b ;
    return (temp < c) ? temp : c;
}

int editDistance(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();

    // Create a table
    int dp[len1+1][len2+1];

    for(int i = 0; i < len2; i++)
        dp[0][i] = i;

    for(int i = 0; i < len1; i++)
        dp[i][0] = i;

    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);  
        } 
    }

    int i = str1.length();
    int j = str2.length();

    while(true)
    {
        if(i ==0 || j == 0)
            break;

        if(str1[i-1] == str2[j-1])
        {
            i = i-1;
            j = j-1; 
        }
        else if(dp[i][j] == dp[i-1][j-1] + 1)
        {
            cout << "Edit " << str2[j-1] << " in " << str2  << " to " << str1[i-1] << " in " << str1 << endl;
            i = i-1;
            j = j-1; 
        }
        else if(dp[i][j] == dp[i-1][j] + 1)
        {
            cout << "Delete in " << str1 << " " << str1[i-1] << endl;
            i = i - 1; 
        }
        else if(dp[i][j] == dp[i][j-1] + 1)
        {
            cout << "Delete in " << str2 << " " << str2[j-1] << endl;
            j = j - 1;
        } 
    }
    return dp[len1][len2]; 
}

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    cout << "The edit distance is: " << editDistance(str1, str2) << endl;
    return 0;  
}
