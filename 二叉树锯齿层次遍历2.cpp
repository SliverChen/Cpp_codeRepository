/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	/*创建一个存放结果的vector<vector<int>>类型变量res 
	判断root是否为空，如果为空则直接 返回res
	创建用于存放节点层数的双端队列deque<int> d1
	创建用于存放节点的双端队列deque<TreeNode*> d2
	初始化：存放层数1和结点root，设置深度为1
	进入循环：(根据d1是否为空)
	  判断深度的奇偶性
	   如果为奇数
	     进入死循环： 
	       创建临时变量nowD和node赋值从d1和d2的前端获取该层数和节点 
	       如果获取的层数与该层数不相同，则停止死循环（用于遍历该层的所有点） 
		   将获取的节点对应的值存放到out中 
	       将d1和d2的前端删除（用于进入下一节点的遍历）
		   先将左节点压进队列中
		   再将右节点压进队列中
	   如果为偶数
	   	 进入死循环：
			与奇数做法类似
			最后在压进队列的操作时，选择先将右节点压进队列，再将左节点压进队列
		将out存放到res中，并将out清空
		此时深度往下+1 
	 
	 最后返回res 
	 
	 */
	 
	 vector<vector<int>> res;
	 if(root) return res;
	 vector<int> out;
	 deque<int> depth;
	 deque<TreeNode*> node;
	 
	 int Depth = 1;  //初始化 
	 depth.push_back(1);
	 node.push_back(root);
	 
	 while(!depth.empty())
	 {
	 	if(Depth%2==1)
	 	{
	 		while(1)
	 		{
	 			int nowDepth = depth.front();
	 			TreeNode* tmp = node.front();
	 			if(nowDepth != depth) break;
	 			depth.pop_front();
	 			node.pop_front();
	 			out.push_back(tmp->val);
	 			
	 			if(tmp->left)
	 			{
	 				depth.push_back(nowDepth+1);
	 				node.push_back(tmp->left);
				 }
				 if(tmp->right)
				 {
				 	depth.push_back(nowDepth+1);
				 	node.push_back(tmp->right);
				 }
			 }
		 }
		 else
		 {
		 	while(1)
		 	{
		 		int nowDepth = depth.back();
		 		TreeNode* tmp = node.back();
		 		if(nowDepth!=depth) break;
		 		depth.pop_back();
		 		node.pop_back();
		 		out.push_back(tmp->val);
		 		if(tmp->right)
		 		{
		 			depth.push_front(nowDepth+1);
		 			node.push_front(tmp->right);
				}
				if(tmp->left)
				{
					depth.push_front(nowDepth+1);
					node.push_front(tmp->left);
				}
			 }
		 }
		 if(!out.empty())
		 	res.push_back(out);
		 out.clear();
		 depth++;
	 }
	 
 }
};
