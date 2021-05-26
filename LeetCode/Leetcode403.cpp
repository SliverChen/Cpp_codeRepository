/*
    Topic: Frog cross the river
    Author: Sliverchen
    Create file date : 2021 / 4 / 29
    Explanation:
        this problem is about to solved by dynamic programing
        so the problem will be depart from two sub problem:
            1)如何定义状态转移方程
            2)最后一步是什么样的
            3)初始状态的设定

    思路：
        要注意有些石子可能不需要经过
        相邻两步存在联系（不是相邻两个石子）
        每遍历到一个石子，就遍历它之前的判断有没有石子能到达它，但是这里需要注意应该选取哪个石子作为它的前一步

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool canCross(const vector<int> &stones)
{
    int n = stones.size();
    if (n == 0 || stones[0] != 0)
        return false;

    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (stones[i] - stones[i - 1] > i) //如果第i-1个石子与第i个石子之间的距离大于i，说明没有路径可以到达第i个石子，直接返回false
            return false;
        for (int j = i - 1; j >= 0; j--)
        {
            int k = stones[i] - stones[j];
            /*
            *如果第i个石子和第j个石子之间的距离大于j+1，
            *则说明没有办法从第j个石子到达第i个石子，
            *也就是说第j个之前的石子也没有办法到达第i个石子，因为第j个石子是在[0,...,j-1,j]中与第i个石子相距最近的石子（题目中的升序）
            *此时可直接跳出对j的遍历
            */
            if (k > j + 1)
                break;
            dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
            if (i == n - 1 && dp[i][k])
                return true;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {0, 1, 3, 6, 10, 13, 15, 18};
    vector<int> nums2 = {0, 1, 3, 6, 10, 15, 16, 21};
    vector<int> nums3 = {0, 1, 2, 3, 4, 8, 9, 11};
    cout << canCross(nums) << endl;
    cout << canCross(nums2) << endl;
    cout << canCross(nums3) << endl;

    system("pause");
    return 0;
}