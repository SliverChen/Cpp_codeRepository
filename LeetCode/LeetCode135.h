/*
Author:SliverChen
Topic: leetCode135 distribute candies
date: 2020/12/24 
*/


/*
初步思路：
设置一个用于存放孩子评分的数据结构
设置一个用于存放孩子应被分配糖果数的数据结构，顺序对应上面的数据结构
 从第一位开始，每两位进行评分的比较，评分高的糖果数+1，评分低的不变，评分相同的两个位置糖果数不变
 将存放糖果数的数据结构中所有>0的糖果数相加，得到最终需要准备的糖果数 

注意： 
一个高评分夹在两个低评分之间的分配情况 
三个相同评分并列的情况 
1 2 87 87 87 2 1的情况 
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
    	
        vector<int> candies(ratings.size(),1); //初始化 
        int count = 0;
        int hrat=0,lrat=0;
        
        for(int i=0;i<ratings.size()-1;i++)  //正序遍历 
        {
            if(ratings[i]==ratings[i+1]) //评分相同则继续 
                continue;
            hrat = ratings[i]>ratings[i+1]?i:i+1;  //获取高低评分的索引 
            lrat = ratings[i]<ratings[i+1]?i:i+1;
            if(candies[hrat]>candies[lrat]) //如果高评分的糖果已经多于低评分则继续 
                continue;
            candies[hrat]=candies[lrat]+1; //如果高评分糖果小于等于低评分，高评分的更新为低评分糖果数+1 
        }

        for(int i=ratings.size()-1;i>0;i--)  //反序遍历 
        {
            if(ratings[i]==ratings[i-1]) //评分相同则继续 
                continue;
                
            hrat = ratings[i]>ratings[i-1]?i:i-1; //获取高低评分的索引 
            lrat = ratings[i]<ratings[i-1]?i:i-1;
            if(candies[hrat]>candies[lrat]) //如果高评分的糖果已经多于低评分则继续 
                continue;
            candies[hrat]=candies[lrat]+1;//如果高评分糖果小于等于低评分，高评分的更新为低评分糖果数+1
        }

        for(int i=0;i<candies.size();i++)
            count+=candies[i];
        return count;
    }
};
