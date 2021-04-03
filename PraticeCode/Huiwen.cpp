/*
    Topic: find the longest HUiwen substring in the string
    Statement:
        1)it can be directly solved by using for-circle to find the suitable substring   Time complexity: O(n^3)
        2)while using for-circle, it can optimize the way of implement, which time complexity will be O(n^2)
        3)it can be solved by using dynamic programming    But dynamic programming is difficult to understand  
        anyway, step-by-step gogogo
*/

#include <cstring>
#include <iostream>
using namespace std;

string FindPalindrome(const string &str)
{
    string substr;

    return substr;
}

int main()
{
    string str = "ababb";
    string substr = FindPalindrome(str);
    printf("the longest Palindrome substring in %s is : %s\n", str, substr);
    system("pause");
    return 0;
}
