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

        anyway, step-by-step gogogo
    Think about it:
        Q: 
            if we want to judge one string if it is Palindrome, how to implement it?
        Tips1:
            The Palindrome string satisfy the property of symmetry
        
        Tips2:
            Every Palindrome string must have a center index(Assume that string is odd)
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

string convert_manacher(const string &str)
{
    char *tempStr = new char[2 * str.size() + 1];
    int size = 0;
    for (auto ch : str)
    {
        tempStr[size++] = '#';
        tempStr[size++] = ch;
    }
    tempStr[size++] = '#';
    tempStr[size] = '\0';
    string newStr(tempStr);
    return newStr;
}

string return_manacher(const string &str, int left, int right)
{
    char *tempStr = new char[right - left + 1];
    string PreStr;
    int j = 0;
    for (int k = left; k < right; k++)
    {
        if (str[k] != '#')
            tempStr[j++] = str[k];
    }
    tempStr[j] = '\0';
    PreStr = tempStr;
    return PreStr;
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
    return subString;
}

string FindPalindrome_manacher(const string &str)
{
    if (str.size() == 1 || str.size() == 0)
        return str;
    int *test; //using for test
    string newStr = convert_manacher(str);
    int Strlen = newStr.size();
    int i, id = -1, R = -1, Max = INT_MIN, MaxIndex = 0;
    int *p = new int[Strlen];
    /*
        this algorithm is traversing from the left side and end to the right side
        so if we can know that there are two index is symmetrical,
            we can make the right one equals the left one in order to reduce the calculation
    */
    for (i = 0; i < Strlen; i++)
    {
        if (i > R) //if index is bigger than the leftest edge
        {
            p[i] = 1; //Initialize palindrome radius(add itself equals one)
            while ((i + p[i]) < Strlen && (i - p[i]) > -1)
            {
                //center on current index
                if (newStr[i + p[i]] == newStr[i - p[i]]) //calculate length of palindrome
                {
                    p[i]++;
                }
                else
                    break;
            }
        }
        else //if index is in the edge
        {
            p[i] = p[2 * id - i] > (R - i) ? (R - i) : p[2 * id - i];
            while ((i + p[i]) < Strlen && (i - p[i]) > -1)
            {
                if (newStr[i + p[i]] == newStr[i - p[i]])
                {
                    p[i]++;
                }
                else
                    break;
            }
        }
        test = &p[i]; //check the current Index data of the radius array
        if (p[i] + i > R)
        {
            R = p[i] + i;
            id = i;
        }
        if (Max < p[i])
        {
            Max = p[i];
            MaxIndex = i;
        }
    }
    //print the radius array
    for (int q = 0; q < Strlen; q++)
    {
        printf("%d ", p[q]);
    }
    printf("\n");

    //get the longest palindrome string
    int left = MaxIndex - p[MaxIndex] + 1;
    int right = p[MaxIndex] + MaxIndex - 1;
    string result = return_manacher(newStr, left, right);
    delete[] p;
    return result;
}

void checkManacher(const string &str)
{
    string substr = FindPalindrome_manacher(str);
    cout << "the longest palindrome string in " << str << " is: " << substr << endl;
}

int main()
{
    //string str = "ababb";
    // string substr = FindPalindrome(str);
    //cout << "the longest Palindrome substring in " << str << " is: " << substr << endl;

    //string str1 = "abccba";
    //checkManacher(str1);
    string str2 = "abbbcbbba";
    checkManacher(str2);
    system("pause");
    return 0;
}
