/*
    Topic: find the longest HUiwen substring in the string
    Statement:
        1)it can be directly solved by using for-circle to find the suitable substring   Time complexity: O(n^3)

        2)while using for-circle, it can optimize the way of implement, which time complexity will be O(n^2)

        3)it can be solved by using dynamic programming    But dynamic programming is difficult to understand  time complexity: O(n)

        4)the famous algorithm is "manacher algorithm",which also be called "horse pull car algorithm"
            statement:
                1)first we should make the length of the string into odd, by using '#' insert
                    for example:
                        string 'abba' ---->   string '#a#b#b#a#'    now the length of string is odd.
                2)then

        anyway, step-by-step gogogo
    Think about it:
        Q: 
            if we want to judge one string if it is Palindrome, how to implement it?
        Tips:
            The Palindrome string satisfy the property of symmetry
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define MIN(a, b) ((a > b) ? (b) : (a))

bool isPalindrome(const string &str)
{
    string left, right;
    int middle;
    if (str.size() == 0 || str.size() == 1) //if str is a letter or null
    {
        return true;
    }

    // by using the property of symmetry, we can divide the string equally
    if (str.size() % 2 == 0) //if str.size() is even
    {
        middle = str.size() / 2;
        left = str.substr(0, middle);               //the left half part is in [0,index-1]
        right = str.substr(middle, str.size() - 1); //the right half part is in[index,str.size()-1]
        reverse(right.begin(), right.end());
    }
    else //if str.size() is odd
    {
        middle = str.size() / 2;
        left = str.substr(0, middle);
        right = str.substr(middle + 1, str.size() - 1);
        reverse(right.begin(), right.end());
    }
    if (left == right) //judge if left equals right
    {
        return true;
    }
    else
        return false;
}

void checkPalindrome(const string &str)
{
    if (isPalindrome(str))
    {
        cout << str << " is a Palindrome string." << endl;
    }
    else
    {
        cout << str << " is not a Palindrome string." << endl;
    }
}

string FindPalindrome_violent(const string &str)
{
    if (str.size() == 1 || str.size() == 0) //if str is a letter or null
    {
        return str;
    }
    string SubString = "";
    string curstr;
    int maxlength = 1;
    //the following situation is based on [str.size() >= 2]
    for (int left = 0; left < str.size() - 1; left++)
    {
        for (int right = left + 1; right <= str.size(); right++)
        {
            if (right < maxlength)
            {
                continue;
            }
            curstr = str.substr(left, right);
            if (isPalindrome(curstr))
            {
                if (maxlength < curstr.size())
                {
                    SubString = curstr;
                    maxlength = SubString.size();
                }
            }
        }
    }

    return SubString;
}

string FindPalindrome_dynamicProgram(const string &str)
{
    if (str.size() == 1 || str.size() == 0)
    {
        return str;
    }
    string subString;
    int left, right;
    int size = str.size();
}

string FindPalindrome_manacher(const string &str)
{
    if (str.size() == 1 || str.size() == 0)
        return str;
    string subString, longestString;
    string newStr;
    vector<int> RadiusArray;
    int j = 0;
    //first we should insert '#' between the nearby letter in str:
    for (auto ch : str)
    {
        newStr[j++] = '#';
        newStr[j++] = ch;
    }
    newStr[j] = '#';

    int mx = 0, id = 0;
    for (int i = 0; newStr[i] != '\0'; i++)
    {
        RadiusArray[i] = mx > i ? MIN(RadiusArray[2 * id - 1], mx - i) : 1;
        while (newStr[i + RadiusArray[i]] == newStr[i - RadiusArray[i]])
            RadiusArray[i]++;
        if (i + RadiusArray[i] > mx)
        {
            mx = i + RadiusArray[i];
            id = i;
        }
    }
    int maxLength = 0, middle = 0;
    for (int i = 0; i < RadiusArray.size(); i++)
    {
        if (maxLength < RadiusArray[i])
        {
            maxLength = RadiusArray[i];
            middle = i;
        }
    }
    subString = newStr.substr(middle, middle + maxLength / 2);
    int k = 0;
    for (auto ch : subString)
    {
        if (ch == '#')
            continue;
        longestString[k++] = ch;
    }
    return longestString;
}

int main()
{
    //string str = "ababb";
    // string substr = FindPalindrome(str);
    //cout << "the longest Palindrome substring in " << str << " is: " << substr << endl;

    string str1 = "abccba";
    string substr1 = FindPalindrome_manacher(str1);
    cout << "the longest Palindrome substring in " << str1 << " is: " << substr1 << endl;

    system("pause");
    return 0;
}
