/*
    Topic:
        Convert string to Integer
*/

#include <cmath>
#include <cstring>
#include <iostream>
#include <typeinfo>
using namespace std;

#define MAX_EDGE pow(2, 31) - 1

int convertCharToInt(const char &ch)
{
    int temp = int(ch);
    return temp - 48;
}

int ConvertInt(const string &str)
{
    char first = str[0];
    if (first != ' ' || first < '0' || first > '9')
        return 0;
    long result = 0;
    int multiple = 0;
    bool flag = true, isNumber = false;
    const char *test;
    for (auto ch = str.rbegin(); ch != str.rend(); ch++)
    {
        if (*ch < '0' || *ch > '9')
        {
            if (isNumber && *ch == '-')
            {
                if (!flag)
                    result += 1;
                result = -result;
                break;
            }
            continue;
        }
        isNumber = true;
        //the type of pow(x,y) is double,
        // we need to use forced type conversion to make it convert to integer----->(int)pow(x,y)
        result += convertCharToInt(*ch) * (long)pow(10, multiple);
        if (result > MAX_EDGE)
        {
            result = MAX_EDGE;
            flag = false;
            break;
        }
        multiple++;
    }
    return (int)result;
}

int main()
{
    string str = "-42";
    int result = ConvertInt(str);
    cout << str << " converts to integer is: " << result << endl;

    system("pause");
    return 0;
}