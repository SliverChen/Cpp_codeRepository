/*
Author: SliverCHen
Topic: LeetCode188--买卖股票的最佳时机
date:2020/12/28 
*/

/*
解题思路：
将prices赋值到一个新的数组new_prices中

对new_prices进行遍历，找到差值最大的两个非负数的位置
如果小的在大的前面，则记录小的作为买入时间，大的作为卖出时间，同时将这两个位置上的值设置为-1，次数+1 
如果大的在小的前面，将这两个位置上的值清空，继续遍历 
直到次数>k 直接结束 
*/

#include<iostream>
#include<vector>
using namespace std;


int main()
{
	vector<int> prices = {2,4,1};
	int k = 2;
	return 0;
}
