/*
    Topic:Achieve B-Tree
    Author:Sliverchen
    Create file date: 2021/4/21 19:04
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class B_Tree;

template <class T>
class BTreeNode
{
public:
    BTreeNode(int _t, bool _leaf);
    void traverse();
    BTreeNode<T> *search(const T &elem);
    void insertNonFull(const T &elem);            //插入未满节点
    void splitChild(const int &i, BTreeNode *&y); //拆分操作

private:
    T *keys;
    int t; //the minimum order
    BTreeNode<T> **childNode;
    int count; // the count of keys
    bool leaf;
    friend B_Tree<T>;
};

template <class T>
class B_Tree
{
public:
    typedef BTreeNode<T> node_t;

public:
    B_Tree();
    B_Tree(const int &neworder);
    ~B_Tree();
    void Insert(const T &elem);
    void Remove(const T &elem);
    bool Contains(const T &elem);
    void traverse();
    void checkContains(const T &elem);

private:
    int minorder;
    node_t *root;
};

//*******************BTreeNode成员函数实现***************************//
template <class T>
BTreeNode<T>::BTreeNode(int _t, bool _leaf)
{
    t = _t;
    leaf = _leaf;
    keys = new T[2 * t - 1];
    childNode = new BTreeNode *[2 * t];
    count = 0;
}

template <class T>
void BTreeNode<T>::traverse()
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (leaf == false)
            childNode[i]->traverse();
        printf("%d ", keys[i]);
    }

    if (leaf == false)
        childNode[i]->traverse();
}

template <class T>
BTreeNode<T> *BTreeNode<T>::search(const T &elem)
{
    int i = 0;
    while (i < count && elem > keys[i]) //找到节点上第一个不比elem小的关键字
        i++;
    if (keys[i] == elem)
        return this;
    if (leaf == true)
        return nullptr;
    else
        return childNode[i]->search(elem);
}

template <class T>
void BTreeNode<T>::insertNonFull(const T &elem)
{
    int i = count - 1;
    if (leaf == true)
    {
        while (i >= 0 && keys[i] > elem)
        {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = elem;
        count = count + 1;
    }
    else
    {
        while (i >= 0 && keys[i] > elem)
            i--;
        if (childNode[i + 1]->count == 2 * t - 1)
        {
            splitChild(i + 1, childNode[i + 1]);
            if (keys[i + 1] < elem)
                i++;
        }
        childNode[i + 1]->insertNonFull(elem);
    }
}

template <class T>
void BTreeNode<T>::splitChild(const int &i, BTreeNode *&y)
{
    BTreeNode *newNode = new BTreeNode(y->t, y->leaf);
    newNode->count = t - 1;

    for (int j = 0; j < t - 1; j++)
        newNode->keys[j] = newNode->keys[j + t];

    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            newNode->childNode[j] = y->childNode[j + t];
    }

    y->count = t - 1;

    for (int j = count; j >= i + 1; j--)
        childNode[j + 1] = childNode[j];

    childNode[i + 1] = newNode;

    for (int j = count - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];

    count = count + 1;
}

//*********************B_Tree成员函数实现********************************?/

template <class T>
B_Tree<T>::B_Tree()
{
    minorder = 3;
    root = new node_t(minorder, true);
}

template <class T>
B_Tree<T>::B_Tree(const int &neworder)
{
    minorder = neworder;
    root = nullptr;
}

template <class T>
B_Tree<T>::~B_Tree()
{
}

template <class T>
void B_Tree<T>::Insert(const T &elem)
{
    if (root == nullptr)
    {
        root = new node_t(minorder, true);
        root->keys[0] = elem;
        root->count = 1;
    }
    else
    {
        if (root->count == 2 * minorder - 1)
        {
            node_t *s = new node_t(minorder, false);
            s->childNode[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < elem)
                i++;
            s->childNode[i]->insertNonFull(elem);

            root = s;
        }

        else
        {
            root->insertNonFull(elem);
        }
    }
}

template <class T>
void B_Tree<T>::Remove(const T &elem)
{
}

template <class T>
bool B_Tree<T>::Contains(const T &elem)
{
    if (root == nullptr || root->search(elem) == nullptr)
        return false;
    return true;
}

template <class T>
void B_Tree<T>::traverse()
{
    if (root)
        root->traverse();
    printf("\n");
}

template <class T>
void B_Tree<T>::checkContains(const T &elem)
{
    if (Contains(elem))
        printf("the value %d is in the tree\n", elem);
    else
        printf("the value %d is not in the tree\n", elem);
}

int main()
{
    B_Tree<int> myBTree(3);
    myBTree.Insert(10);
    myBTree.Insert(20);
    myBTree.Insert(5);
    myBTree.Insert(6);
    myBTree.Insert(12);
    myBTree.Insert(30);
    myBTree.Insert(7);
    myBTree.Insert(17);

    printf("Traversal of the constucted tree is:\n");
    myBTree.traverse();

    myBTree.checkContains(6);
    myBTree.checkContains(15);

    system("pause");
    return 0;
}