/*
Author: SliverChen
Topic: LeetCode205��ͬ���ַ���
date: 2020/12/27 
*/

//�ⷨһ������ⷨ�����ַ�����ÿһ���ַ�ӳ��һ����ֵ��ͨ���Ƚ���ֵ���ж������ַ����Ƿ�ṹ��ͬ��
//ʱ�临�Ӷȣ�O(n) 
//��ʱ44ms���ڴ棺7.3M 
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


//�ⷨ���� ����find()���ض�Ӧ�ַ����ֵĵ�һ��λ����Ϊÿ���ַ����صı�־
//��ʱ��4ms���ڴ棺7.1M 
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
