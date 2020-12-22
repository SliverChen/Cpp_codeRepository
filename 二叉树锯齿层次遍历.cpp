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
	//������������ʾ��ʱ���ᱨ�������ύ��������ʾ��ʱ�ͻᱨ����ʾ 
	//Line 26: Char 24: runtime error: member access within null pointer of type 'TreeNode' (solution.cpp)
	public:
		vector<vector<int>> zigzagLevelOrder(TreeNode* root)
		{
		//����һ��return�������͵���ʱ����res ������vector<vector<int>>
		//�������ڴ��ÿһ��Ľ���ı���out ������ vector<int>
		//��������ջs1 s2 ������stack<TreeNode*>���ڱ���ÿһ��Ľ��,s1�������ұ��棬s2�������󱣴�
		//���Ƚ�����㱣�浽s1�� 
		
		//����ѭ�� (����s1��s2�Ƿ�Ϊ��)
		
		//������ѭ��1 (����s1��Ϊ��)
		//����ʱ����tmp��s1�еĵ����������ͬʱ��pop()���ɾ����
		//��s1�ĵ��ŵ�out�б�ʾ�ò�ĵ㣬ͬʱ��s1�ĵ���ӽ������ҷ���s2�� 
		//��out�ŵ�����res��,ͬʱ���out�е��� 
		
		//������ѭ��2 (����s2��Ϊ��)
		//����ʱ����tmp��s2�еĵ����������ͬʱ��pop()���ɾ����
		//��s2�ĵ��ŵ�out�б�ʾ�ò�ĵ㣬ͬʱ��s2�ĵ���ӽ����ҵ������s1�� 
		//��out�ŵ�����res��,ͬʱ���out�е��� 
		
		//return res
		
		vector<vector<int>> res;  //��Ž�� 
		if(!root) return res;   //��Ϊ�ս�� ֱ�ӷ���res 
		vector<int> out;    //���ÿһ��Ľ��
		stack<TreeNode*> s1;
		stack<TreeNode*> s2;  //�������ÿһ��������ʾ˳��
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
