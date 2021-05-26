/*
    Topic: 二叉树展开为链表
    Author: Sliverchen
    Create file date : 2021 / 5 / 25
*/
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

void flatten(TreeNode *root)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> s;

    TreeNode *newRoot = new TreeNode(0);
    TreeNode *curNode = newRoot;

    s.push(root);

    TreeNode *tempNode;
    while (!s.empty())
    {
        tempNode = s.top();
        s.pop();
        curNode->right = tempNode;
        curNode = curNode->right;
        if (tempNode->left)
            s.push(tempNode->left);
        if (tempNode->right)
            s.push(tempNode->right);
    }
    root = newRoot->right;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    flatten(root);

    system("pause");
    return 0;
}