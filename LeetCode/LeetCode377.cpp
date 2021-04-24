/*
    Topic:  Combine plus IV
    Author: Sliverchen
    Create file date: 2021 / 4 / 24
    Explanation:
        这道题需要注意的是，由于本身题目限制答案必然在32位整数范围内，
        那么也同时暗示了中间值有可能出现溢出的情况，因此为了保证溢出问题的解决
        1、可以将类型int转换成unsigned long long从而保证不出现溢出异常
        2、在进行赋值的时候取INT_MAX与原来的值之中较小者
        
        当然由于vscode的编译器与leetcode的不同：
            在vscode中溢出问题不会终止程序的进行，而是根据编译器自身的机制对溢出的值进行修改
            从而使得自动解决溢出问题

            而在leetcode中，由于使用的是stackflow的异常排查功能，一旦出现溢出，就会终止程序，向用户发送异常所在
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int combinationSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    if (target < nums[0])
    {
        return 0;
    }

    //Initialization
    //最终取dp[target]，因此长度应该是target+1
    vector<unsigned long long> dp(target + 1, 0);

    //初始化让nums本身的值对应的组合数都为1
    //这里应该初始化nums中比target小的组合数，遇到比target大的nums值直接结束循环，否则将超过dp长度
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > target)
            break;
        dp[nums[i]] = 1;
    }

    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[j] >= i)
                break;
            dp[i] += dp[i - nums[j]];
            printf("dp[%d] is %d\n", i - nums[j], dp[i - nums[j]]);
        }
    }
    return dp[target];
}

int main()
{
    vector<int> a = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600, 610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750, 760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970, 980, 990, 111};
    cout << combinationSum(a, 999) << endl;
    system("pause");
    return 0;
}