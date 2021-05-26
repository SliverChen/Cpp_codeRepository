/*
    Topic:  Leaf similiar
    Author: Sliverchen
    Create file date: 2021 / 5 / 10
    Explanation:
        从左到右------>前序遍历或中序遍历
*/

#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int elem) : val(elem), left(nullptr), right(nullptr) {}
};

class solution
{
    vector<int> r1, r2;

    void getR1Leaf(TreeNode *&t)
    {
        if (t == nullptr)
            return;
        getR1Leaf(t->left);
        if (t->left == nullptr && t->right == nullptr)
        {
            r1.push_back(t->val);
            return;
        }
        getR1Leaf(t->right);
    }

    void getR2Leaf(TreeNode *&t)
    {
        if (t == nullptr)
            return;
        getR2Leaf(t->left);
        if (t->left == nullptr && t->right == nullptr)
        {
            r2.push_back(t->val);
            return;
        }
        getR2Leaf(t->right);
    }

public:
    bool LeafSimiliar(TreeNode *root1, TreeNode *root2)
    {
        r1.clear();
        r2.clear();
        getR1Leaf(root1);
        getR2Leaf(root2);
        if (r1 == r2)
            return true;
        return false;
    }
};
