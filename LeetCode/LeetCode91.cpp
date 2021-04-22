/*
    Topic: LeetCode 91

    Using Algorithm:
        Dynamic Program
    
    Explanation:
        对于给定字符串S，长度为n，字符从左到右依次为S[1],S[2],...,S[n]
        设f_i表示字符串S的前i个字符s[1..i]的解码方法数
        在进行状态转移时，我们可以考虑最后一次编码使用了S中的哪些字符，即有以下两种情况

        1、使用了一个字符，即S[i]进行解码，那么只要S[i]≠0，它就可以被解码成某个字母
        由于剩余的前i-1个字符的解码方法数为f_i-1，因此状态转移方程为：
            
                            f_i = f_i-1     ,S[i]≠0
        
        2、第二种情况是使用了两个字符，即S[i-1]和S[i]进行编码，此时S[i-1]不能等于0，并且
        S[i-1] 和 S[i] 组成的整数必须 ≤ 26
        由于剩余的前i-2个字符的解码方法数为f_i-2，因此状态转移方程为:
                            f_i = f_i-2     ,S[i-1]≠0 && 10*S[i-1] + S[i] ≤ 26

            注意这种情况下的i必须要 > 1，否则S[i-1]不存在
        
        上述动态规划的边界条件为：
                        f_0 = 1
        即空字符串可以有一种解码方法，解码出一个空字符串

*/

#include <cstring>
#include <iostream>
#include <tuple> //the head file of the function "tie"
#include <vector>
using namespace std;

int convertCharToInt(const char &ch)
{
    return ch - 48;
}

int numDecodings(const string &s)
{
    int n = s.size();
    if (n == 0)
        return 0;
    if (n == 1)
    {
        if (s == "0")
            return 0;
        return 1;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];
        if (i > 1 && s[i - 2] != '0' && (10 * convertCharToInt(s[i - 2]) + convertCharToInt(s[i - 1]) <= 26))
            dp[i] += dp[i - 2];
    }
    return dp[n];
}

int numDecodings_Opt(const string &s)
{
    int n = s.size();
    if (n == 0)
        return 0;
    if (n == 1)
    {
        if (s == "0")
            return 0;
        return 1;
    }

    //deminish the expend of the memory
    int a = 1, b, c;
    //a = f_i-1  b = f_i-2  c = f_i

    for (int i = 1; i < n + 1; i++)
    {
        c = 0;
        if (s[i - 1] != '0')
            c += a;
        if (i > 1 && s[i - 2] != '0' && 10 * (s[i - 2] - '0') + (s[i - 1] - '0') <= 26)
            c += b;
        // b = a;
        // a = c;
        tie(b, a) = {a, c};
    }
    return c;
}

int main()
{
    cout << numDecodings("1234") << endl;
    cout << numDecodings_Opt("1106") << endl;
    system("pause");
    return 0;
}