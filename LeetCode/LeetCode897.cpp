/*
    Topic:  IncreasingBST
    Author: Sliverchen
    Create file date； 2021 / 4 / 25
*/

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class solution
{
private:
    TreeNode *resNode;

public:
    void Inorder(TreeNode *t)
    {
        if (t == nullptr)
            return;
        Inorder(t->left);

        resNode->right = t;
        t->left = nullptr;
        resNode = t;

        Inorder(t->right);
    }

    TreeNode *IncreasingBST(TreeNode *&root)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *dummyNode = new TreeNode(-1); //新建起点
        resNode = dummyNode;                    //从dummynode开始
        Inorder(root);
        return dummyNode->right; //除去起点之后的链表
    }
};

void InorderTraverse(TreeNode *&t)
{
    if (t == nullptr)
        return;
    InorderTraverse(t->left);
    printf("%d->", t->val);
    InorderTraverse(t->right);
}

int main()
{
    solution mysolution;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);
    InorderTraverse(root);
    printf("\n");
    TreeNode *newRoot = mysolution.IncreasingBST(root);
    InorderTraverse(newRoot);
    printf("\n");
    system("pause");
    return 0;
}
