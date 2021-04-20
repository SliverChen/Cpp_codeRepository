/*
    Topic: leetcode 28
*/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int Strstr_violent(const string &haystack, const string &needle)
{
    if (needle == "")
        return 0;
    int PreLength = haystack.size();
    int Length = needle.size();
    if (PreLength < Length)
        return -1;
    string curStr;
    for (int i = 0; i <= PreLength - Length; i++)
    {
        curStr = haystack.substr(i, Length);
        if (curStr == needle)
            return i;
    }
    return -1;
}

int Strstr_KMP(string haystack, string needle)
{
    int m = haystack.size(), n = needle.size();
    if (n == 0)
        return 0;

    //前面加空格使其下标从1开始
    haystack.insert(haystack.begin(), ' ');
    needle.insert(needle.begin(), ' ');

    //构建next数组，数组长度为模式字符串的长度
    vector<int> next(m + 1, 0);

    //从i = 2,j = 0开始，i≤模式字符串的长度
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j > 0 && needle[i] != needle[j + 1])
            j = next[j];

        if (needle[i] == needle[j + 1])
            j++;
        next[i] = j;
    }

    //匹配过程 i = 1,j = 0开始，
    for (int i = 1, j = 0; i <= n; i++)
    {
        // 匹配不成功
        while (j > 0 && haystack[i] != needle[j + 1])
            j = next[j];
        //匹配成功
        if (haystack[i] == needle[j + 1])
            j++;
        if (j == m)
            return i - m;
    }
}

int Strstr_KMP_Opt(const string &haystack, const string &needle)
{
    int n = haystack.size(), m = needle.size();
    if (m == 0)
        return 0;
    vector<int> next(m);
    for (int i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && needle[i] != needle[j])
        {
            j = next[j - 1];
        }
        if (needle[i] == needle[j])
            j++;
        next[i] = j;
    }
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && haystack[i] != needle[j])
            j = next[j - 1];
        if (haystack[i] == needle[j])
            j++;
        if (j == m)
            return i - m + 1;
    }
    return -1;
}

int main()
{
    cout << Strstr_violent("hello", "ll") << endl;
    cout << Strstr_KMP_Opt("hello", "ll") << endl;
    cout << Strstr_KMP("hello", "ll") << endl;
    system("pause");
    return 0;
}