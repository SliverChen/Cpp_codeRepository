/*
    Topic: convert string to int
    statement: 
        we will use if-else structure to solve this problem
*/

#include <cstring>
#include <iostream>
using namespace std;

int convertCharToInt(const char &ch)
{
    return (int)ch - '0';
}

int convertStringToInt(const string &str)
{
    bool isSigned = false;
    bool isNegative = false;
    bool isOutofRange = false;
    bool isNumber = false;

    long long result = 0;
    for (auto ch : str)
    {
        if (ch == ' ')
            continue;
        else if (ch >= '0' && ch <= '9')
        {
            isNumber = true;
            result = result * 10 + convertCharToInt(ch);
            if (result > INT_MAX)
            {
                isOutofRange = true;
                result = INT_MAX;
            }
        }
        else if (ch == '+' || ch == '-')
        {
            if (isNumber || isSigned)
                break;
            isSigned = true;
            if (ch == '-')
                isNegative = true;
        }
        else
        {
            break;
        }
    }
    if (isNegative)
    {
        if (isOutofRange)
        {
            result += 1;
        }
        result = -result;
    }
    return result;
}

int main()
{
    string s = "-123132123123123123123";

    cout << convertStringToInt(s) << endl;
    system("pause");
    return 0;
}