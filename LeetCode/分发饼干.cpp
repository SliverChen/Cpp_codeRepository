/*
Author:SliverChen
Topic: LeetCode455 分发饼干
date: 2020/12/25 
*/

/*
初步思路：
首先将孩子的胃口和饼干尺寸按从大到小排序
逐一遍历判断胃口和尺寸的大小比较
如果胃口>尺寸则该胃口的孩子轮空，继续遍历
如果胃口<=尺寸则得到满足的孩子数+1
如此最终得到满足的孩子数 
*/

bool comp(const int &a,const int &b){return a>b;}

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(),g.end(),comp);
        sort(s.begin(),s.end(),comp);
        int j=0;
        for(int i=0;i<g.size();i++)
        {
            if(j==s.size()) break;
            if(g[i]>s[j]) continue;
            if(g[i]<=s[j])
            {
                count++;
                j++;
            }   
        }
        return count;
    }
};
