/*
    Topic:二叉树遍历的迭代实现
    Author:Sliverchen
    Create file date : 2021 / 5 / 19
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(nullptr), right(nullptr) {}
    TreeNode(int ele) : val(ele), left(nullptr), right(nullptr) {}
};

void PreOrder(TreeNode *&root)
{
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *tmp = s.top();
        s.pop();
        cout << tmp->val << " ";
        if (tmp->right != nullptr)
            s.push(tmp->right);
        if (tmp->left != nullptr)
            s.push(tmp->left);
    }
    cout << endl;
}

void PostOrder_PreOrderOpt(TreeNode *&root)
{
    vector<int> res;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *tmp = s.top();
        s.pop();
        res.push_back(tmp->val);
        if (tmp->left != nullptr)
            s.push(tmp->left);
        if (tmp->right != nullptr)
            s.push(tmp->right);
    }
    reverse(res.begin(), res.end());
    for (auto value : res)
        cout << value << " ";
    cout << endl;
}

void pushLeft(TreeNode *p, stack<TreeNode *> &s)
{
    while (p != nullptr)
    {
        s.push(p);
        p = p->left;
    }
}

void pushRight(TreeNode *p, stack<TreeNode *> &s)
{
    while (p != nullptr)
    {
        s.push(p);
        p = p->right;
    }
}

void InOrder(TreeNode *p)
{
    stack<TreeNode *> s;
    while (true)
    {
        pushLeft(p, s);
        if (s.empty())
            break;
        cout << s.top()->val << " ";
        p = s.top()->right;
        s.pop();
    }
    cout << endl;
}

void PostOrder(TreeNode *p)
{
    //pair结构用于保存结点以及该结点的右子树是否已被访问
    stack<pair<TreeNode *, bool>> s;
    while (!s.empty() || p)
    {
        if (p != nullptr)
        {
            s.push({p, false});
            p = p->left;
        }
        else
        {
            p = s.top().first->right;
            bool status = s.top().second;
            s.top().second = true;

            if (p && !status)
                continue;
            else
            {
                cout << s.top().first->val << " ";
                s.pop();
                p = nullptr;
            }
        }
    }
    cout << endl;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    PreOrder(root);
    InOrder(root);
    PostOrder(root);
    PostOrder_PreOrderOpt(root);
    system("pause");
    return 0;
}