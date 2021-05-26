/*
    Topic: reverseNumber
    Author: Sliverchen
    Create file date : 2021 / 5 / 3
    Explanation:
        注意题目假设了不允许存储64位整数，也就是说不能用long类型去存储结果然后判断是否大于INT_MAX
        所以需要在计算之前判断计算后的结果是否大于INT_MAX
*/

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int reverse(const int &x)
{
    string str = to_string(x);
    cout << str << endl;
    bool isNegative = false;
    if (str[0] == '-')
    {
        isNegative = true;
        str = str.substr(1, str.size() - 1);
    }
    bool isNumber = false;
    int result = 0;
    for (auto value = str.rbegin(); value != str.rend(); value++)
    {
        if (!isNumber && *value == '0')
            continue;
        else
        {
            isNumber = true;
            if (result > INT_MAX / 10) //如果计算后结果会超过int范围，那么就直接让result=0并且退出循环
            {
                result = 0;
                break;
            }
            result = result * 10 - 48 + *value;
        }
    }
    if (isNegative)
        result = -result;
    return result;
}

int main()
{
    cout << reverse(42) << endl;
    cout << reverse(-31) << endl;
    system("pause");
    return 0;
}