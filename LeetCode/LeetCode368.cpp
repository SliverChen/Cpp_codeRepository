/*
    Topic: largest divisible subset
    Author : SliverChen
    Create file date : 2021 / 4 / 23
    Explanation:
        this question is similiar with the question 300: longest increasing sublist
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    //dynamic program
    vector<int> dp(n, 1);
    int maxSize = 1;
    int maxVal = nums[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (dp[i] > maxSize)
        {
            maxSize = dp[i];
            maxVal = nums[i];
        }
    }

    vector<int> result;
    if (maxSize == 1)
    {
        result.push_back(maxVal);
        return result;
    }
    for (int i = n - 1; i >= 0 && maxSize > 0; i--)
    {
        if (dp[i] == maxSize && maxVal % nums[i] == 0)
        {
            result.push_back(nums[i]);
            maxVal = nums[i];
            maxSize--;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {2, 3, 4, 6, 7, 9, 12, 8};
    vector<int> result = largestDivisibleSubset(nums);
    for (auto value : result)
        printf("%d ", value);
    printf("\n");
    system("pause");
    return 0;
}