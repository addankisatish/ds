#include<iostream>
using namespace std;

// Algorithm:
// Make them equal sized by adding 0 at the beginning of smaller string
// perform bit addition:
// Sum = a XOR b XOR c
// Carry = (a AND b) OR (b AND c) OR (a AND c)
//

int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();

    if(len1 < len2)
    {
        for(int i = 0; i < (len2 - len1); i++)
           str1 = '0' + str1;
        return len2; 
    }
    else if(len1 > len2)
    {
        for(int i = 0; i < (len1 - len2); i++)
           str2 = '0' + str2;
    }
    return len1;
}

string addBitStrings(string str1, string str2)
{
    string result;
    
    int length = makeEqualLength(str1, str2);
    
    int carry = 0;
    for(int i = length-1; i >=0; i--)
    {
        int firstbit = str1.at(i) - '0';
        int secondbit = str2.at(i) - '0';

        int sum = (firstbit ^ secondbit ^ carry);
      
        if(sum == 1) 
            result = '1' + result;
        else
            result = '0' + result;

        carry = (firstbit && secondbit) || (secondbit && carry) || (firstbit && carry);
    }

    if(carry)
        result = '1' + result;        

    return result;
}

string addBinaryStrings(string a, string b)
{
    string result = "";
    int s = 0;

    int i = a.size()-1;
    int j = b.size()-1;
    while((i >= 0) || (j >=0) || (s == 1))
    {
        s += ((i >= 0) ? a[i] - '0' : 0);
        s += ((j >= 0) ? b[j] - '0' : 0);

        result = char(s%2 + '0') + result;
        
        // compute carry
        s /= 2;

        i--;
        j--;
    }
    return result;
}

int main()
{
    string str1 = "1100011";
    string str2 = "10";

    cout << str1 << endl;
    cout << str2 << endl;
    string str3 = addBitStrings(str1, str2);
    cout << "The sum is : " << str3 << endl;
    string str4 = addBinaryStrings(str1, str2);
    cout << "The sum is : " << str4 << endl;

    return 0;
}

