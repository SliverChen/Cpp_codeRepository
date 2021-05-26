/*
    Topic: depart the array into some segments to make sure the max segment is least
    Author: Sliverchen
    Date : 2021 / 4 / 26
*/

/*
思路：
    题目追求的是划分中的最大值最小
    因此对于小的物品重量，我们可以归并到大的物品重量下组合成一个划分
        对于大的物品重量，尽可能得将它们单独归并到一个个划分中
    
    将题目转换为更加具体的问题：
        是否存在一个装载下限x_ans，使得
            当x >= x_ans时，可以在D天中完成运输，
            当x <  x_ans时，不能在D天中完成运输
        此时x_ans即为所求
    
    此时问题从上述问题转换为：
        在一堆x中，能否找到满足上述条件的x_ans------>此时利用二分查找找出x_ans
        其中x包括可行和不可行的方案
        很显然，x越小，说明装载能力越小，划分的数量可能越大，同时也越不可能完成运输，
        因此二分查找的初始边界可以定为：
            左边界---->x = max(nums)
            右边界---->x = sum(nums)
        
    上述问题的前置问题是：
        如何求出一堆x的结果？
    
    也就是说，我们需要对每个x都需要进行一个判断结果：
        给定一个装载能力x，判断能否在D天中完成装载
    
    上述问题的实现方法可利用贪心算法：
        由于题目限制必须按照nums的顺序进行装载运输，并且此时装载上限x已知，
        那么我们可以先将所有物品都放到同一天中
        如果此时总重量 > x，则将最后的物品放到下一天中，直到总重量<= x为止
        随后对下一天作同样的判断，直到所有划分中对应的总重量都 <= x为止

    上述步骤对于任意x可能出现的情况：
        1）若对于x，划分数 >  D，则视为不能在D天中完成运输
        2）若对于x，划分数 <= D，则视为能在D天中完成运输
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int getSum(const vector<int> &nums, int left, int right)
{
    int sum = 0;
    for (int i = left; i <= right; i++)
        sum += nums[i];
    return sum;
}

int getMax(const vector<int> &nums)
{
    int max = INT_MIN;
    for (auto num : nums)
        if (max < num)
            max = num;
    return max;
}

int shipWithInDays(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    int left = getMax(nums), right = getSum(nums, 0, n - 1);
    vector<int> canTrans;

    int curleft, curright;
    int sum, dayscount;

    //贪心算法求每个装载上限x能否在target天内完成运输

    //****************************问题处在贪心算法中------>效率有点低下 导致超时  泪目了

    for (int capacity = left; capacity <= right; capacity++)
    {
        curleft = 0;
        curright = n - 1;
        dayscount = 1;
        if (getSum(nums, curleft, curright) <= capacity) //如果一天就能满足所有物品的装载
        {
            curleft = n - 1; //跳过下面的循环
        }
        while (curleft < n - 1)
        {
            sum = getSum(nums, curleft, curright);
            if (sum <= capacity)
                break;
            while (sum > capacity)
            {
                curright--;
                sum = getSum(nums, curleft, curright);
            }
            dayscount++;
            curleft = curright + 1;
            curright = n - 1;
        }
        printf("ths capacity %d will take %d days to finish the work\n", capacity, dayscount);

        if (dayscount > target) //如果划分天数比D天要大，则记录为不可行
            canTrans.push_back(0);
        else //如果划分天数不超过D天，则记录为可行
            canTrans.push_back(1);
    }

    /*二分查找找到装载下限x_ans
     *此时  canTrans[i]  对应 装载上限 i + left
     *注意 canTrans 由于是从小的装载能力到大的装载能力的遍历，因此左半部分判定为不可行，右半部分判定为可行
     *这里求的是可行的左边界，因此针对左边界的二分查找算法，需要进行特殊处理
    */
    int mid;
    curleft = 0;
    curright = canTrans.size();
    while (curleft < curright)
    {
        mid = (curleft + curright) >> 1;
        if (canTrans[mid] == 1) //如果中间值对应为可行，则舍弃掉右半部分(因为需要的是最小的，右边都是比mid要大的装载能力)
            curright = mid;
        else if (canTrans[mid] == 0) //如果中间值对应为不可行，则舍弃掉左半部分（装载能力越小，越不可行，左边都是比mid要小的装载能力）
            curleft = mid + 1;
    }

    return curright + left;
}

int main()
{
    vector<int> nums = {3, 2, 2, 4, 1, 4};
    cout << shipWithInDays(nums, 3) << endl;
    system("pause");
    return 0;
}