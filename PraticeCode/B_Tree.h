/*
    Topic:  B-Tree 实现
    Author: Sliverchen
    Create file date: 2021 / 5 / 19
*/

#pragma once
#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

const int m = 3;

typedef int KeyType;

typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

typedef struct BTNode
{
    int keyNum;                //关键字数量
    KeyType key[m + 1];        //结点的关键字数组
    struct BTNode *parent;     //结点的父亲节点
    struct BTNode *ptr[m + 1]; //结点的子节点
} BTNode, *BTree;

/*
    功能1：在B树中查找关键字为k的结点并返回到re中
    包含的函数：
        SearchBTree
        SearchKey
    返回的结构：
        result：
            pt：结点
            i：关键字在结点中的子序
            tag：表示能否查找成功
*/
typedef struct
{
    BTree pt; //指向找到的结点
    int i;    //在节点中关键字的子序  (1 <= i <= m)
    int tag;  //表示能否查找成功
} result;
Status SearchBTree(BTree t, KeyType k, result &re);
int searchKey(BTree node, KeyType k); //二分查找

/*
    功能2：在B树中插入一个关键字k
    包含的函数：
        InsertBTree(BTree &root,KeyType k)：主实现函数
        InsertNode(BTree &root,int KeySite,KeyType k,BTree &node)：在B树某一层插入一个关键字，其中node是root对应的孩子
        SplitToTwo(BTree &root,BTree &SplitRight)：分割节点，一半留在root，一般留在node
        NewBroot(BTree &root,BTree left,BTree right,KeyType k)：生成一个新根
*/
Status InsertBTree(BTree &root, KeyType k);
Status SplitToTwo(BTree &root, BTree &SplitRight);
Status NewBroot(BTree &root, BTree left, BTree right, KeyType k);
Status InsertNode(BTree &root, int KeySite, KeyType k, BTree &node);

/*
    功能3：在B树中删除关键字k
    包含的函数:
        DeleteBTree(BTree &root,KeyType k)：著实现函数
        DeleteNode(BTree &node,int KeySite)：删除位置在KeySite的结点
        Restore(BTree &node)：  
        Merge(BTree &left,BTree &right,BTree &parent)： //合并结点
*/
Status DeleteBTree(BTree &root, KeyType k);
Status DeleteNode(BTree &node, int KeySite);
Status Restore(BTree &node);
Status Merge(BTree &left, BTree &right, BTree &parent);

/*
    功能4：打印B树
    包含的函数：
        Aoprint(BTree T,int depth)：利用凹入表打印B树
        AscOrderTraverse(BTree T)：升序遍历
        DesOrderTraverse(BTree T)：降序遍历
        Depth(BTree T)：获取结点T的深度
        Leaves(BTree T)：获取结点T的叶子数
*/
void Aoprint(BTree T, int depth);
void AscOrderTraverse(BTree &T);
void DesOrderTraverse(BTree &T);
int Depth(BTree &T);
int Leaves(BTree &T);

/*
    功能5：销毁B树
    包含的函数:
        Destroy(BTree &T)：销毁B树
*/
void Destroy(BTree &T);

#endif