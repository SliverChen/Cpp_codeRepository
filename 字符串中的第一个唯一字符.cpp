/*
Author:SliverChen
Topic: leetCode387-�ַ����еĵ�һ��Ψһ�ַ� 
date: 2020/12/23
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int count=0;
        vector<int> out(200,0);
        string::iterator iter = s.begin();
        for(;iter<s.end();iter++)
            out[int(*iter)]++;  //��¼���ִ��� 
        for(iter=s.begin();iter<s.end();iter++,count++)
        {
            if(out[int(*iter)]==1)  //�������ұ����õ���һ��Ψһ���ֵ��ַ� 
            {
                return count;
            }
        }
        return -1;
    }
};
