/*
    Topic: the number that only appear once time II
    Author: Sliverchen
    Create file date : 2021 / 4 / 30
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    sort(nums.begin(), nums.end());

    int i, curValue = nums[0];
    for (i = 0; i < n; i++)
    {
        if (i + 1 >= n)
            return nums[i];
        if (curValue == nums[i + 1])
        {
            i = i + 2;
        }
        else
        {
            return nums[i];
        }
        if (i + 1 >= n)
            cout << "end error" << endl;
        curValue = nums[i + 1];
    }
    return curValue;
}

int main()
{
    vector<int> nums = {2, 2, 3, 2};
    cout << singleNumber(nums) << endl;

    nums = {0, 1, 0, 1, 0, 1, 99};
    cout << singleNumber(nums) << endl;
    system("pause");
    return 0;
}