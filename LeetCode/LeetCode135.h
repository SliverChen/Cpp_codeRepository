/*
Author:SliverChen
Topic: leetCode135 distribute candies
date: 2020/12/24 
*/


/*
����˼·��
����һ�����ڴ�ź������ֵ����ݽṹ
����һ�����ڴ�ź���Ӧ�������ǹ��������ݽṹ��˳���Ӧ��������ݽṹ
 �ӵ�һλ��ʼ��ÿ��λ�������ֵıȽϣ����ָߵ��ǹ���+1�����ֵ͵Ĳ��䣬������ͬ������λ���ǹ�������
 ������ǹ��������ݽṹ������>0���ǹ�����ӣ��õ�������Ҫ׼�����ǹ��� 

ע�⣺ 
һ�������ּ�������������֮��ķ������ 
������ͬ���ֲ��е���� 
1 2 87 87 87 2 1����� 
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
    	
        vector<int> candies(ratings.size(),1); //��ʼ�� 
        int count = 0;
        int hrat=0,lrat=0;
        
        for(int i=0;i<ratings.size()-1;i++)  //������� 
        {
            if(ratings[i]==ratings[i+1]) //������ͬ����� 
                continue;
            hrat = ratings[i]>ratings[i+1]?i:i+1;  //��ȡ�ߵ����ֵ����� 
            lrat = ratings[i]<ratings[i+1]?i:i+1;
            if(candies[hrat]>candies[lrat]) //��������ֵ��ǹ��Ѿ����ڵ���������� 
                continue;
            candies[hrat]=candies[lrat]+1; //����������ǹ�С�ڵ��ڵ����֣������ֵĸ���Ϊ�������ǹ���+1 
        }

        for(int i=ratings.size()-1;i>0;i--)  //������� 
        {
            if(ratings[i]==ratings[i-1]) //������ͬ����� 
                continue;
                
            hrat = ratings[i]>ratings[i-1]?i:i-1; //��ȡ�ߵ����ֵ����� 
            lrat = ratings[i]<ratings[i-1]?i:i-1;
            if(candies[hrat]>candies[lrat]) //��������ֵ��ǹ��Ѿ����ڵ���������� 
                continue;
            candies[hrat]=candies[lrat]+1;//����������ǹ�С�ڵ��ڵ����֣������ֵĸ���Ϊ�������ǹ���+1
        }

        for(int i=0;i<candies.size();i++)
            count+=candies[i];
        return count;
    }
};
