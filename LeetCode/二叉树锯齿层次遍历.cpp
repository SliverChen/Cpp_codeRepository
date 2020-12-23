/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
	//该做法在运行示例时不会报错，但是提交运行其他示例时就会报错，提示 
	//Line 26: Char 24: runtime error: member access within null pointer of type 'TreeNode' (solution.cpp)
	public:
		vector<vector<int>> zigzagLevelOrder(TreeNode* root)
		{
		//创建一个return函数类型的临时变量res 类型是vector<vector<int>>
		//创建用于存放每一层的结果的变量out 类型是 vector<int>
		//创建两个栈s1 s2 类型是stack<TreeNode*>用于保存每一层的结点,s1用于向右保存，s2用于向左保存
		//首先将根结点保存到s1中 
		
		//进入循环 (根据s1或s2是否不为空)
		
		//进入子循环1 (根据s1不为空)
		//用临时变量tmp将s1中的点逐个遍历，同时用pop()逐个删除。
		//将s1的点存放到out中表示该层的点，同时将s1的点的子结点从左到右放入s2中 
		//将out放到最后的res中,同时清空out中的数 
		
		//进入子循环2 (根据s2不为空)
		//用临时变量tmp将s2中的点逐个遍历，同时用pop()逐个删除。
		//将s2的点存放到out中表示该层的点，同时将s2的点的子结点从右到左放入s1中 
		//将out放到最后的res中,同时清空out中的数 
		
		//return res
		
		vector<vector<int>> res;  //存放结果 
		if(!root) return res;   //若为空结点 直接返回res 
		vector<int> out;    //存放每一层的结果
		stack<TreeNode*> s1;
		stack<TreeNode*> s2;  //创建存放每一层结果的显示顺序
		s1.push(root);
		while(!s1.empty() || !s2.empty()) 
		{
			while(!s1.empty())
			{
				TreeNode* tmp = s1.top();
				s1.pop();
				out.push_back(tmp->val); 
				if(tmp->left) s2.push(tmp->left);
				if(tmp->right) s2.push(tmp->right);
				
			}
			if(!out.empty()) 
				res.push_back(out);
			out.clear();
			
			while(!s2.empty())
			{
				TreeNode* tmp = s2.top();
				s2.pop();
				out.push_back(tmp->val); 
				if(tmp->right) s1.push(tmp->right);
				if(tmp->left) s1.push(tmp->left);
				
			}
			if(!out.empty())
				res.push_back(out);
			out.clear();
		}
		return res;
	}
};
