/*
    Topic: longest increasing sublist
    Author:SliverChen
    Create file date : 2021 / 4 / 23
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int LengthofLIS(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, 1);

    int maxSize = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (maxSize < dp[i])
        {
            maxSize = dp[i];
        }
    }
    return maxSize;
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 2, 3};
    cout << LengthofLIS(nums) << endl;
    system("pause");
    return 0;
}