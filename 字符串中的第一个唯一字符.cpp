/*
Author:SliverChen
Topic: leetCode387-字符串中的第一个唯一字符 
date: 2020/12/23
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int count=0;
        vector<int> out(200,0);
        string::iterator iter = s.begin();
        for(;iter<s.end();iter++)
            out[int(*iter)]++;  //记录出现次数 
        for(iter=s.begin();iter<s.end();iter++,count++)
        {
            if(out[int(*iter)]==1)  //从左往右遍历得到第一个唯一出现的字符 
            {
                return count;
            }
        }
        return -1;
    }
};
