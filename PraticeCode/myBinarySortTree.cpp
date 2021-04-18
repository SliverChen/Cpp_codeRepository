/*
    Topic: achieve Binary sort Tree (Binary serach Tree)
    Author: SliverChen
    Create file Date: 2021/4/18 15:06
    Explanations:
        the properties of the Binary sort Tree are as follows:
            1)Every node obeys the rules :
                 the size of leftchildNode,Node,rightchildNode by sort is : leftchildNode > Node > rightchildNode
            2)in this data structure, every two elements can not be identical
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct TreeNode
{
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T elem)
    {
        val = elem;
        left = NULL;
        right = NULL;
    }
    TreeNode()
    {
        val = T();
        left = NULL;
        right = NULL;
    }
};

template <class T>
class BinarySortTree
{
public:
    BinarySortTree()
    {
        size = 0;
        root = new TreeNode<T>();
        isRootGetNum = false;
    }

    BinarySortTree(const vector<int> &arr)
    {
    }

    bool insert(T elem)
    {
        if (!isRootGetNum)
        {
            root->val = elem;
            size++;
            isRootGetNum = true;
            return true;
        }
        else
        {
            TreeNode<T> *newNode = new TreeNode<T>(elem);
            TreeNode<T> *curNode = root;
            while (curNode)
            {
                if (curNode->val > elem)
                {
                    if (!curNode->left)
                    {
                        curNode->left = newNode;
                        size++;
                        return true;
                    }
                    curNode = curNode->left;
                }
                else
                {
                    if (!curNode->right)
                    {
                        curNode->right = newNode;
                        size++;
                        return true;
                    }
                    curNode = curNode->right;
                }
            }
        }
        return false;
    }

    void printTree()
    {
        if (!isRootGetNum)
            return;
        printf("%d ", root->val);
        printTree(root->left);
        printTree(root->right);
    }

    void printTree(TreeNode<T> *node)
    {
        if (!node)
            return;
        printf("%d ", node->val);
        printTree(node->left);
        printTree(node->right);
    }

private:
    int size;
    TreeNode<T> *root;
    bool isRootGetNum;
};

int main()
{
    BinarySortTree<int> mytree;
    mytree.insert(5);
    mytree.insert(2);
    mytree.insert(6);
    mytree.insert(3);
    mytree.insert(4);
    mytree.insert(1);

    mytree.printTree();
    printf("\n");
    system("pause");
    return 0;
}