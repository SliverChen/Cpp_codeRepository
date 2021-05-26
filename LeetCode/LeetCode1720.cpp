/*
    Topic: encode 异或
    Author:Sliverchen
    Create file date : 2021 / 5 / 6
    Explanation:
        这里需要注意位运算的规律：
        1、异或自身奇数次等于自身
        2、A & （A-1）去掉最后一位1
        3、A & 1 == 0 判断奇偶

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> decode(vector<int> &nums, int first)
{
    //x，y，z满足x || y = z，现在已知x和z，求y
    //则不难得出，y = x || z

    //Initialization
    //长度必然是nums.size()+1
    vector<int> result;

    //将first存入result中
    result.push_back(first);

    int curValue;
    int preValue = first;
    for (auto value : nums)
    {
        curValue = value ^ preValue;
        result.push_back(curValue);
        preValue = curValue;
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> decodenums = decode(nums, 1);
    for (auto value : decodenums)
    {
        printf("%d ", value);
    }
    printf("\n");

    system("pause");
    return 0;
}