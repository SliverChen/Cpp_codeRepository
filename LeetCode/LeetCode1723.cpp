/*
    Topic:  minimum Time Required
    Author: Sliverchen
    Create file date : 2021 / 5 / 8
    Explanation:
        这道题可以抽象成：
            对于一个给定的数组，现要求将其分成k份，使得这k份中最大的一份最小（组合问题）
            要想满足这个条件，应该尽可能地将数组平分成k份，而不会出现某一份为0的情况
            上述描述相当于加速迭代的情况，因为上述情况必然不是最优的
        这道题跟Leetcode1011相似，是它的一个变式
        区别在于
            Leetcode1011限定了数组的元素排序
            Leetcode1723不限定数组的元素排序
        
        这道题可以回溯算法、递归解决
        回溯模板：
            void backtracking(...)
            {
                if(终止条件){
                    存放结果;
                    return;
                }

                for(选择：本层集合中元素（树中结点孩子的数量就是集合的大小)
                {
                    处理节点;
                    backtracking(路径，选择列表); // 递归
                    回溯，撤销处理结果
                }
            }


        对于这道题而言，我们可以利用树结构来划分集合，划分k份则对应树结构有k层，每一层对应一个划分
        
        并且根据一个划分中必须有一个以上的元素这个性质进行剪枝操作，即
        如果已知集合大小为n，需要划分为k份，那么对于第i层而言，当前遍历的划分大小m需要满足
                                n - m >= k - i
        即
                                m <= n + i - k


        这里有几个问题：
            如何记录每一次遍历所获得的划分？
            首先要想将集合划分为k份，那么就要知道前k-1份是什么样子的，对此我们可以在当前层遍历的时候记录 当前的子集元素总和 以及 剩余集合
                1）当前的子集的元素总和   用于更新当前划分的最大值
                2）剩余集合              用于下一层的遍历
            在遍历的时候遵循从左往右进行遍历

            如何在第i层中获取固定数量的子集？
                计算起始偏移量h1和末尾偏移量h2，并且h1，h2满足
                    h2 - h1 = 当前固定的子集大小-1
                    0 <= h1 <= 当前遍历的子集大小-1
                结合上述不等式，我们可以先遍历h1的大小，然后根据 h2 = h1 + 当前固定的子集大小 - 1 得到h2的大小
        
        上述描述有个错误的地方：
            偏移量的使用需要在元素连续的情况下使用，如果不连续，偏移量这个概念就无法使用到这个情景下
            比如从[1,2,4,7,8]中选择[1,2,7]作为子集，显然此时起始偏移量h1和末尾偏移量不满足上述等式

        出现上述问题的主要原因在于：
            我们在上面限定了划分k份对应树结构k层，如此我们需要在一层中获取像[1,2,7]这样的子集的操作。但是显然这样是比较困难的
    
        可行方案：
            假设划分数为3，则
            1）从第一个划分开始，把第一个划分所有可能的子集自顶向下形成树结构，每层比上一层的元素个数少1，层数直到元素个数等于集合大小-划分数+1为止
            2）遍历到每个子集的时候，记录当前的剩余子集，并将其作为第二个划分的集合，重复上述的步骤
            3）遍历到第三个划分时，此时已等于3，则直接取传进来的集合元素总和作为第三个划分的大小

        我们想得过于复杂了：
            这道题可以使用DFS来解决，那么关键在于DFS的构造

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class solution
{
    int WorkerNum; //工人的个数
    int JobNum;    //工作数量
    int result = INT_MAX;
    vector<int> Jobs;

    int getMax()
    {
        int ans = INT_MIN;
        for (auto value : Jobs)
            if (value > ans)
                ans = value;
        return ans;
    }

    void dfs(int count, int used, vector<int> &sum, int Max)
    {
        if (Max >= result) //如果当前划分比之前的大，则舍弃掉
            return;
        if (count == JobNum) //如果最后一项工作已被分配，并且最大值小于当前的result，则令result等于当前的最大值
        {
            result = Max;
            return;
        }

        if (used < WorkerNum)
        {
            sum[used] += Jobs[count];
            dfs(count + 1, used + 1, sum, max(sum[used], Max));
            sum[used] = 0;
        }

        for (int i = 0; i < used; i++)
        {
            //需要加上剪枝的操作
            //如果第i名工人已经被分配工作，之后的工人没有被分配到工作，那么就需要i++
            //如果所有工人都被分配工作，则按照正常的思路进行搜索
            sum[i] += Jobs[count];
            dfs(count + 1, used, sum, max(sum[i], Max));
            sum[i] -= Jobs[count];
        }
    }

public:
    int minimumTimeRequired(vector<int> &jobs, int k)
    {
        JobNum = jobs.size(); //初始化类中的集合大小
        Jobs = jobs;          //初始化类中的集合
        WorkerNum = k;        //初始化类中的子集数量

        //如果工作数量与工人数量相同，最小必然是数组中的最大值
        //因为此时最优情况之一是一个工作对应一个工人
        if (JobNum == WorkerNum)
        {
            return getMax(); //直接返回数组的最大值
        }
        vector<int> arr(WorkerNum, 0);
        dfs(0, 0, arr, 0);
        return result;
    }
};
int main()
{
    vector<int> nums = {1, 2, 4, 7, 8};
    solution mysolution;
    cout << mysolution.minimumTimeRequired(nums, 2) << endl;
    system("pause");
    return 0;
}