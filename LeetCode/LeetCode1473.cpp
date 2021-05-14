/*
    Topic: Print the house III
    Author:Sliverchen
    Create date file: 2021 / 5 / 4
    Explanation:
    1)    这里的target意味着一开始的街区是没有划分的
          给定一个target，要求房子涂上什么颜色从而划分出target个街区

    2)    一开始需要从target和houses序列入手判断需要的涂色方案
          如果houses = [0,2,1,2,0] target=3 
          注意这里houses已经出现了三个街区，此时已经满足target个街区的条件
          这里引出一个问题：如何从houses中得知已划分多少个街区?
    
    3)    这道题需要用到三维动态规划：
          定义dp[i][j][k]为将[0,i]的房子涂上颜色，最末尾第i个房子的颜色为j，并且它属于第k个街区时，需要的最少花费

*/

#include <iostream>
#include <vector>
using namespace std;

static constexpr int INFTY = INT_MAX / 2;

int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
{
    //将颜色调整为从0开始，没有被涂色标记为-1
    for (int &c : houses)
        --c;

    //创建dp，并将所有元素初始化为极大值
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, INFTY)));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (houses[i] != -1 && houses[i] != j)
                continue;
            for (int k = 0; k < target; k++)
            {
                for (int j0 = 0; j0 < n; j0++)
                {
                    if (j == j0)
                    {
                        if (i == 0)
                        {
                            if (k == 0)
                                dp[i][j][k] = 0;
                        }
                        else
                        {
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                        }
                    }
                    else if (i > 0 && k > 0)
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j0][k - 1]);
                }
                if (dp[i][j][k] != INFTY && houses[i] == -1)
                    dp[i][j][k] += cost[i][j];
            }
        }
    }
    int ans = INFTY;
    for (int j = 0; j < n; j++)
        ans = min(ans, dp[m - 1][j][target - 1]);
    return ans = INFTY ? -1 : ans;
}

int main()
{
}