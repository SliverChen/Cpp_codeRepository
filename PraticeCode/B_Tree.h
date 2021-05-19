/*
    Topic:  B-tree 实现
    Author: Sliverchen
    Create file date : 2021 / 5 / 19
*/
#ifndef BTREE_CLASS
#define BTREE_CLASS

static const int M = 3;

struct BTNode
{
    int keyNum;                  //关键字个数
    int key[2 * M - 1];          //关键字数组
    struct BTNode* child[2 * M]; //子节点数组
    bool isLeaf;                 //是否为叶子节点
};


class BTree
{
public:
    typedef BTNode node;

public:
    BTree();
    ~BTree();
    node* Find(int key, int& index); //一般性的查找操作
    void insert(int key);            //一般性的插入操作
    void remove(int key);            //一般性的删除操作
    void printRow();                 //按层级打印

private:
    node* root;

    //在关键字少于2M-1的时候插入
    void InsertNonFull(node* pNode, int key);

    //当child结点有2M-1个关键字时，分裂此结点
    void SplitChild(node* parent, int i, node* child);

    //两个关键字数为M-1的结点合并
    void merge(node* parent, node* pNode1, node* pNode2, int index);

    //找到比pNode结点第一个关键字小的最大关键字（前驱节点）
    int predecessor(node* pNode);

    //找到比pNode结点最后一个关键字大的最小关键字（后继节点）
    int successor(node* pNode);

    //pNode1向parent要一个结点key[index]，parent向pNode0要一个结点，pNode1关键字个数为M-1
    void ExchangeLeftNode(node* parent, node* pNode0, node* pNode1, int index);

    //pNode2向parent要一个结点key[index]，parent向pNode1要一个节点，pNode2关键字为M-1
    void ExchangeRightNode(node* parent, node* pNode1, node* pNode2, int index);

    //删除关键字个数不少于M的结点
    void RemoveNonLess(node* pNode, int key);

    //模拟磁盘写入操作（数据库的存储）
    void DiskWrite(node* pNode);

    //模拟磁盘读取操作（数据库的读取）
    void DiskRead(node* pNode);

    //找到关键字key所在的结点和关键字索引
    node *Search(node* pNode, int key, int& index);
};

#endif