/*
    Topic: Leetcode 303
    Author: Sliverchen
    Create file date : 2021 /4/ 22
*/

#include <iostream>
#include <vector>
using namespace std;

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        int size = nums.size();
        dp.resize(size);
        for (int i = 0; i < size; i++)
            dp[i] = nums[i];
        for (int i = 1; i < size; i++)
            dp[i] += dp[i - 1];
    }
    int NumRange(int left, int right)
    {
        int newRight = right >= dp.size() ? dp.size() - 1 : right;
        if (left == 0)
            return dp[newRight];
        else
            return dp[newRight] - dp[left - 1];
    }

private:
    vector<int> dp;
};

int main()
{

    vector<int> nums = {1, 2, -1, 0, 3};
    NumArray *newarray = new NumArray(nums);
    cout << newarray->NumRange(1, 2) << endl;
    cout << newarray->NumRange(1, 3) << endl;
    cout << newarray->NumRange(0, 2) << endl;
    cout << newarray->NumRange(0, 4) << endl;
    system("pause");
    return 0;
}