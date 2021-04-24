/*
    Topic: Jump game
    Author:Sliverchen
    Create file date : 2021 / 4 / 23
*/

#include <iostream>
#include <vector>
using namespace std;

bool JumpGame(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = 1;
    //dp[i] signs that if the frog can go to the No.i stone
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && j + nums[j] >= i)
            {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[n - 1];
}

void Test(vector<int> nums)
{
    if (JumpGame(nums))
        printf("it can go to the destination\n");
    else
        printf("it can not go to the destination\n");
}

int main()
{
    Test({3, 4, 0, 1, 2});
    Test({2, 1, 0, 1, 4});
    system("pause");
    return 0;
}