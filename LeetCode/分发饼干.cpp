/*
Author:SliverChen
Topic: LeetCode455 �ַ�����
date: 2020/12/25 
*/

/*
����˼·��
���Ƚ����ӵ�θ�ںͱ��ɳߴ簴�Ӵ�С����
��һ�����ж�θ�ںͳߴ�Ĵ�С�Ƚ�
���θ��>�ߴ����θ�ڵĺ����ֿգ���������
���θ��<=�ߴ���õ�����ĺ�����+1
������յõ�����ĺ����� 
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
