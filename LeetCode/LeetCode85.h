/*
Author: SliverChen
Topic: LeetCode85 最大矩形
date:2020/12/26 
*/

/*
解题思路： 
1、首先判断矩阵是否为null 是则直接返回0
2、然后判断矩阵是否含有1，是则设定初始面积1，否则返回0
3、逐行遍历，记录第一个1出现的列

*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
        return 0;
        int rows=matrix.size();
        int cols=matrix[0].size();
        int maxArea=0;
        //记忆化动态数组
        vector<vector<int>> rect(rows,vector<int>(cols));
        for(int i=0;i<rows;i++)
        {
            //针对每一行计算[0,col]能够形成的最大矩形
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j]=='1')
                {
                    //如果当前是第一个元素需要单独处理
                    if(j==0)
                    rect[i][j]=1;
                    //rect[i][j]代表[i][j]位置能够形成的宽度，是[i][j-1]加1
                    else
                    rect[i][j]=rect[i][j-1]+1;

                }
                else
                {
                    //如果为‘0’，则为0
                    rect[i][j]=0;
                }
                int minwidth=rect[i][j];
                //这个地方的理解是难点
                //当前要确定matrix[i][j]能形成的最大矩形
                //方法是通过通过当前行逐行递减，意味着高度（hegiht）逐渐增加
				//(这个过程中为了提高时间效率,通过`if(rect[row][j]==0) break;`
				//然后再通过比较当前获得宽度与之前动态规划在相应位置获得宽度比较，得到最小的宽度，
				//进而更新最大矩形长度。
                for(int row=i;row>=0;row--)
                {
                    if(rect[row][j]==0)
                    break;
                    //获得高
                    int height=i-row+1;
                    //获得最小宽度
                    minwidth=min(minwidth,rect[row][j]);
                    maxArea=max(maxArea,height*minwidth);
                }
            }
        }
        return maxArea;
    }
}
