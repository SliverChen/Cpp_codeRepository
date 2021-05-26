/*
    Topic: SUm of Squares
    Author: Sliverchen
    Create file date : 2021 / 4 / 28
*/

/*
    思考：
        已知一条边的长度，判断是否存在以该边作为第三条边的直角三角形

    思路：
        首先尝试一下枚举的方法：
            注意这里的c是非负的，说明0也可以取
        缺陷比较明显：
            如果c的值很大，则需要遍历很多次才能到达合适的a，b选区范围
        优化：
            如何加速遍历a，b的选值范围？
            1、由于已知C的值，那么对于a,b,c而言，如果已知a的值，那么b的值可以根据题目的式子 a^2 + b^2 = c 计算可得，减少不必要的计算
                注意开平方根的时候：
                    如果开出来的是整数说明对于当前的a和b满足上述的式子
                    如果开出来的是浮点数说明对于当前的a和b不满足上述的式子
                因此我们需要比较开平方根的浮点型和整型b是否相等

            3、我们可以设定双指针------->（双指针的关键在于左右边界的选取
            假设a<=b，设定初始值a = 0, b = sqrt(c)那么
                当a^2 + b^2 == c 时
                    返回true
                当a^2 + b^2  < c 时
                    a++
                当 a^2 + b^2 > c 时
                    b--
                当 a > b 时
                    返回false

*/

#include <cmath>
#include <iostream>
using namespace std;

bool judgeSquareSum(const int &c) //暴力枚举  时间复杂度为 O(n^2)
{
    //当遍历的平方和比c大时，即可终止当前数值的遍历
    //注意溢出的问题  题目限制 0 < c <= 2^31 - 1   有可能pow(a,2) + pow(b,2) 的值会超过int的范围
    long a = 0, b;
    long curValue;
    for (; a * a <= c; a++)
    {
        for (b = a; b * b <= c; b++)
        {
            curValue = pow(a, 2) + pow(b, 2);
            if (curValue == c)
                return c;
            else if (curValue > c)
                break;
        }
    }
    return false;
}

bool judgeSquareSum_Opt(const int &c) //sqrt得到b，减少遍历次数
{
    long a = 0;
    double b;
    for (; a * a <= c; a++)
    {
        b = sqrt(c - pow(a, 2));
        if (b == (int)b)
        {
            return true;
        }
    }
    return false;
}

bool judgeSquareSum_Opt2(const int &c) //双指针操作  （最优方案）
{
    int a = 0, b = sqrt(c);
    long curValue;
    while (a <= b)
    {
        curValue = pow(a, 2) + pow(b, 2);
        if (curValue == c)
            return true;
        else if (curValue > c)
            b--;
        else if (curValue < c)
            a++;
    }
    return false;
}

int main()
{
    printf("the value 5 is :%d\n", judgeSquareSum_Opt(5));
    printf("the value 4 is :%d\n", judgeSquareSum_Opt(4));
    printf("the value 1 is :%d\n", judgeSquareSum(1));
    printf("the value 100000 is :%d\n", judgeSquareSum(100000));
    printf("the value 2147483646 is %d\n", judgeSquareSum_Opt2(2147483646));
    // printf("the value %d is :%d \n", INT_MAX, judgeSquareSum(INT_MAX));   //超时

    system("pause");
    return 0;
}