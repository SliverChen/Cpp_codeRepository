/*
    Topic: Brick wall
    Author: Sliverchen
    Create file date: 2021 / 5 / 2
    Explanation；
        1）一开始需要理解数据的意义：
            给定二维数组wall,wall[i][j]表示第i行从左至右数第j块砖的宽度
        2）接着思考怎么画出一条自顶向下的线：
        3）然后思考如何计算线穿过的砖块数量
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int leastBricks(vector<vector<int>> &wall)
{
    //由于没有说明每一行总的宽度是多少，因此我们需要获取第一行的总宽度作为参照

    //记录宽度
    int totalWidth = 0;
    for (auto value : wall[0])
        totalWidth += value;

    //记录高度
    int height = wall.size();

    //根据宽度创建一个个距里左边缘的记录表（除了最右边缘外）
    //1 表示 线在距离最左边缘1个单位的右边缘
    //2 表示 线在距离最左边缘2个单位的右边缘

    //这里使用哈希表的原因是：线距离最左边缘不是连续的，我们只需要出现过的距离
    //如果同时出现1和1000000，使用数组来记录距离时会导致复杂度很大
    unordered_map<int, int> map;
    //但是这里又有一个问题：如果想要记录所有距离，那么就需要遍历整个二维数组

    //下面的操作也是遍历整个二维数组，但是又不能共存，先尝试一下吧------->这个内存消耗在21.2  beat45.55%
    for (int i = 0; i < height; i++)
    {
        int curwidth = 0;
        for (auto width : wall[i])
        {
            curwidth += width;
            map[curwidth] = 0;
        }
    }
    //遍历每一行的砖块，记录每一行的线与最左边缘的距离
    for (int i = 0; i < height; i++)
    {
        int curwidth = 0;
        for (auto width : wall[i])
        {
            curwidth += width;
            if (curwidth == totalWidth) //除去最右边缘的记录
                break;
            map[curwidth]++;
        }
    }

    //遍历哈希表，找到出现次数最多的距离，利用高度-出现次数即为解
    int max = 0;
    for (auto &p : map)
    {
        if (p.second > max)
            max = p.second;
    }
    return height - max;
}

int main()
{
    unordered_map<int, int> map;
    map[1] = 2;
    map[3] = 4;
    unordered_map<int, int>::iterator it;
    for (it = map.begin(); it != map.end(); it++)
    {
        printf("%d : %d\n", (*it).first, (*it).second);
    }
    system("pause");
    return 0;
}
