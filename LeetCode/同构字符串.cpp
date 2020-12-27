/*
Author: SliverChen
Topic: LeetCode205—同构字符串
date: 2020/12/27 
*/

//解法一：菜鸟解法（对字符串中每一个字符映射一个数值，通过比较数值来判断两个字符串是否结构相同）
//时间复杂度：O(n) 
//用时44ms，内存：7.3M 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
	    map<char,int> style_s;
	    map<char,int> style_t;
	    int value_s = 1,value_t = 1;
	    for(int i=0;i<s.size();i++)
	    {
	    	if(style_s[s[i]]==0)
		    {
		    	style_s[s[i]] = value_s;
		    	value_s++;
		    }
		    if(style_t[t[i]]==0)
		    {
			    style_t[t[i]] = value_t;
			    value_t++;
		    }
	    }
		
	    for(int i=0;i<s.size();i++)
	    {
		    if(style_s[s[i]]!=style_t[t[i]])
		    {
			    return false;
		}
			
	}
	return true;
    }
};


//解法二： 利用find()返回对应字符出现的第一个位置作为每个字符独特的标志
//用时：4ms，内存：7.1M 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int i=0;
        while(i<s.size())
        {
            if(s.find(s[i])!=t.find(t[i]))
                return false;
            i++;
        }
        return true;
    }
}; 
