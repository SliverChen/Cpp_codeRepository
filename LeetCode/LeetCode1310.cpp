/*
    Topic: XOR queries
    Author: Sliverchen
    Create file date : 2021 / 5 / 12
*/

#include <iostream>
#include <vector>
using namespace std;

/*
    显然这道题的暴力计算法思路比较简单，只需按照给定的每个查询范围计算范围内的异或和
    但是不难看出，其中重复计算的部分有很多
    导致最坏的复杂度为O(n^n)
*/

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> result;
    for (auto query : queries)
    {
        int ans = arr[query[0]];
        for (int i = query[0]; i <= query[1]; i++)
        {
            ans = ans ^ arr[i];
        }
        result.push_back(ans);
    }
    return result;
}

/*
    对此我们需要思考：
        对于后面重复计算的区域，我们如何利用前面计算的结果快速得到区域内的异或和？

    根据异或的特性：
        对于任意x,y，有
            x^y^x = y
        注意，这里的y可以是一个元素，也可以是多个元素的集合，x同理
    
    结合上面的特性，我们可以首先求得arr中前n项异或和（这里n表示区域的右边界）
    然后根据queries中的区域，异或左边界外的异或和
    因为前n项异或和包括了左边界外的异或和，只要我们再把前n项异或和与左边界外的异或和异或一次，那么得到的就是区域内的异或和

*/

vector<int> xorQueries_Opt(vector<int> &arr, vector<vector<int>> &queries)
{
    int n = arr.size();
    vector<int> xorArr(n);
    xorArr[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        xorArr[i] = xorArr[i - 1] ^ arr[i];
    }

    vector<int> result;
    for (auto query : queries)
    {
        int left = query[0], right = query[1];
        if (left == 0)
            result.push_back(xorArr[right]);
        else
            result.push_back(xorArr[right] ^ xorArr[left - 1]);
    }

    return result;
}