/*
Author:SliverChen
Topic: LeetCode455 分发饼干
date: 2020/12/25 
*/

/*
初步思路：
首先将孩子的胃口和饼干尺寸按从大到小排序
设定初始饼干的索引值0
逐一遍历孩子胃口判断胃口和尺寸的大小比较
如果胃口>尺寸则该胃口的孩子轮空，继续遍历
如果胃口<=尺寸则得到满足的孩子数+1，同时饼干的索引值加1
如果饼干已遍历完成则提前退出循环
如此最终得到满足的孩子数 
*/

/*
第二思路：利用贪心算法
首先思考：
    1、当某个孩子可以被多个糖果满足时，是否需要优先用某个糖果满足这个孩子？
    2、当某个糖果可以满足多个孩子时，是否需要优先满足某个孩子？
    3、贪心规律是什么？

贪心规律：
    1、某个糖果如果不能满足某个孩子，则该糖果也一定不能满足需求因子更大的孩子
    2、某个孩子可以用更小的糖果满足，则没必要用更大的糖果满足，因为可以保留更大的糖果满足需求因子更大的孩子
    3、孩子的需求因子更小则更容易被满足，故优先从需求因子小的孩子尝试，可以得到正确的结果
    （因为题目追求的是更多的孩子被满足，所以用一个糖果去满足需求因子较小或者较大的孩子都是一样的）
*/

bool comp(const int &a, const int &b) { return a > b; }

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int count = 0;
        sort(g.begin(), g.end(), comp);
        sort(s.begin(), s.end(), comp);
        int j = 0;
        for (int i = 0; i < g.size(); i++)
        {
            if (j == s.size())
                break;
            if (g[i] > s[j])
                continue;
            if (g[i] <= s[j])
            {
                count++;
                j++;
            }
        }
        return count;
    }
};
