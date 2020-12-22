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
	/*����һ����Ž����vector<vector<int>>���ͱ���res 
	�ж�root�Ƿ�Ϊ�գ����Ϊ����ֱ�� ����res
	�������ڴ�Žڵ������˫�˶���deque<int> d1
	�������ڴ�Žڵ��˫�˶���deque<TreeNode*> d2
	��ʼ������Ų���1�ͽ��root���������Ϊ1
	����ѭ����(����d1�Ƿ�Ϊ��)
	  �ж���ȵ���ż��
	   ���Ϊ����
	     ������ѭ���� 
	       ������ʱ����nowD��node��ֵ��d1��d2��ǰ�˻�ȡ�ò����ͽڵ� 
	       �����ȡ�Ĳ�����ò�������ͬ����ֹͣ��ѭ�������ڱ����ò�����е㣩 
		   ����ȡ�Ľڵ��Ӧ��ֵ��ŵ�out�� 
	       ��d1��d2��ǰ��ɾ�������ڽ�����һ�ڵ�ı�����
		   �Ƚ���ڵ�ѹ��������
		   �ٽ��ҽڵ�ѹ��������
	   ���Ϊż��
	   	 ������ѭ����
			��������������
			�����ѹ�����еĲ���ʱ��ѡ���Ƚ��ҽڵ�ѹ�����У��ٽ���ڵ�ѹ������
		��out��ŵ�res�У�����out���
		��ʱ�������+1 
	 
	 ��󷵻�res 
	 
	 */
	 
	 vector<vector<int>> res;
	 if(root) return res;
	 vector<int> out;
	 deque<int> depth;
	 deque<TreeNode*> node;
	 
	 int Depth = 1;  //��ʼ�� 
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
