/*
    Topic: find the longest HUiwen substring in the string
    Statement:
        1)it can be directly solved by using for-circle to find the suitable substring   Time complexity: O(n^3)
        2)while using for-circle, it can optimize the way of implement, which time complexity will be O(n^2)
        3)it can be solved by using dynamic programming    But dynamic programming is difficult to understand  
        anyway, step-by-step gogogo
    Think about it:
        Q: 
            if we want to judge one string if it is Palindrome, how to implement it?
        Tips:
            The Palindrome string satisfy the property of symmetry
*/

#include <cstring>
#include <iostream>
using namespace std;

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
        middle = str.size() / 2 - 1;
        left = str[0, middle];                   //the left half part is in [0,index-1]
        right = str[middle + 1, str.size() - 1]; //the right half part is in[index,str.size()-1]
    }
    else //if str.size() is odd
    {
        middle = str.size() / 2;
        left = str[0, middle - 1];
        right = str[middle + 1, str.size() - 1];
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

string FindPalindrome(const string &str)
{
    if (str.size() == 1 || str.size() == 0) //if str is a letter or null
    {
        return str;
    }
    string substr;
    int maxlength;
    //the following situation is based on [str.size() >= 2]
    for (int i = 0; i < str.size() - 1; i++) //fixed left point
    {
        for (int left = i; left < str.size() - 1; left++)
        {
            for (int right = left + 1; right < str.size(); right++)
            {
                        }
        }
    }

    return substr;
}

int main()
{
    string str = "ababb";
    string substr = FindPalindrome(str);
    cout << "the longest Palindrome substring in " << str << " is: " << substr << endl;

    system("pause");
    return 0;
}
