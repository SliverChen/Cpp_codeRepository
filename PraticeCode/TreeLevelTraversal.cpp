/*
    Topic: 二叉树的层次遍历实现
    Author: Sliverchen
    Create file date : 2021 / 5 / 19

    Explanation:
        思路:
            利用队列的结构进行实现
            将root入队
            
            进行循环（如果队列不为空）
                获取队头元素，出队
                判断队头元素是否包含左子节点，有->入队
                判断队头元素是否包含右子节点，有->入队
*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int elem) : val(elem), left(nullptr), right(nullptr) {}
};

void LevelTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curNode = q.front();
        q.pop();
        cout << curNode->val << " ";
        if (curNode->left != nullptr)
            q.push(curNode->left);
        if (curNode->right != nullptr)
            q.push(curNode->right);
    }
    cout << endl;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    LevelTraversal(root);
    system("pause");
    return 0;
}
