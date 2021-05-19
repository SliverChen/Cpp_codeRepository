#include "B_Tree.h"
#include <iostream>
#include <queue>
using namespace std;

typedef BTNode node;

/*
这里需要注意一个问题
    如果BTNode的结构体是定义在类内部，那么关于BTNode类型的函数都无法在类外实现
    这是因为只有在声明一个类变量的时候BTNode结构体才会被创建
    否则相当于没有这个结构
    就算我们在前面声明了一个struct BTNode;来表示有一个这样的结构体
    这样也是无法与类内部的结构体同属类型的
*/

BTree::BTree()
{
    root = new BTNode();
    root->isLeaf = true;
    root->keyNum = 0;
    DiskWrite(root); //模拟写入操作
}

BTree::~BTree()
{
    struct BTNode *pNode;
    queue<struct BTNode *> q;
    q.push(root);
    while (!q.empty())
    {
        pNode = q.front();
        q.pop();
        if (pNode->isLeaf)
            continue;
        for (int i = 0; i <= pNode->keyNum; ++i)
            q.push(pNode->child[i]);
        delete pNode;
    }
}

node *BTree::Find(int key, int &index)
{
}

void BTree::insert(int key)
{
}

void BTree::remove(int key)
{
}

void BTree::printRow()
{
}

void BTree::InsertNonFull(node *pNode, int key)
{
    int i = pNode->keyNum - 1; //从pNode的关键字数组最右边开始
    if (pNode->isLeaf)
    {
        while (i >= 0 && key < pNode->key[i]) //将比插入值大的关键字往右移
        {
            pNode->key[i + 1] = pNode->key[i];
            i--;
        }
        pNode->key[i + 1] = key; //将key插入到i+1处
        pNode->keyNum++;
        DiskWrite(pNode);
    }
    else //如果pNode不是叶子结点
    {
        while (i >= 0 && key < pNode->key[i])
            --i;
        i++;
        DiskRead(pNode->child[i]);
        if (pNode->child[i]->keyNum == 2 * M - 1) //如果当前子节点的关键字等于2M-1，则需要进行分裂
        {
            SplitChild(pNode, i, pNode->child[i]);
            if (key > pNode->key[i]) //如果key比上移到父结点的关键字大
                i++;
        }
        InsertNonFull(pNode->child[i], key);
    }
}

void BTree::SplitChild(node *parent, int i, node *child)
{
}

void BTree::merge(node *parent, node *pNode1, node *pNode2, int index)
{
}

int BTree::predecessor(node *pNode)
{
}

int BTree::successor(node *pNode)
{
    int lastElem = pNode->key[pNode->keyNum - 1];
}

void BTree::ExchangeLeftNode(node *parent, node *pNode0, node *pNode1, int index)
{
}

void BTree::ExchangeRightNode(node *parent, node *pNode1, node *pNode2, int index)
{
}

void BTree::RemoveNonLess(node *pNode, int key)
{
}

void BTree::DiskWrite(node *pNode)
{
    //不操作
}

void BTree::DiskRead(node *pNode)
{
    //不操作
}

node *BTree::Search(node *pNode, int key, int &index)
{
    int i = 0;
    while (i < pNode->keyNum && key > pNode->key[i])
        i++;
    if (i < pNode->keyNum && key == pNode->key[i])
    {
        index = i;
        return pNode;
    }
    if (pNode->isLeaf)
    {
        return NULL;
    }
    else
    {
        DiskRead(pNode->child[i]);
        return Search(pNode->child[i], key, index);
    }
}
