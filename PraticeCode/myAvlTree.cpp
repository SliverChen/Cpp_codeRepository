#include "myAvlTree.h"
#include <algorithm>
#include <iostream>
using namespace std;

//get maximum node
template <class T>
node_t *&AvlTree<T>::FindMax(node_t *&t)
{
}

//get minimum node
template <class T>
node_t *&AvlTree<T>::FindMin(node_t *&t)
{
}

//clear
template <class T>
void AvlTree<T>::clear()
{
    clear(root);
}

template <class T>
void AvlTree<T>::clear(node_t *&t)
{
    if (t == nullptr)
        return;
    else
    {
        clear(t->left);
        clear(t->right);
        delete t;
    }
}

//get the height of node
template <class T>
int AvlTree<T>::GetHeight(node_t *&t)
{
    return t == nullptr ? -1 : t->height;
}

//left child node rotation
template <class T>
void AvlTree<T>::rotateWithLeftChild(node_t *&k2)
{
    node_t *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(GetHeight(k2->left), GetHeight(k2->right)) + 1;
    k1->height = max(GetHeight(k1->left), k2->height) + 1;
    k2 = k1;
}

//right child node rotation
template <class T>
void AvlTree<T>::rotateWithRightChild(node_t *&k2)
{
    node_t *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(GetHeight(k2->left), GetHeight(k2->right)) + 1;
    k1->height = max(GetHeight(k1->right), k2->height) + 1;
    k2 = k1;
}

//left child node double rotation
template <class T>
void AvlTree<T>::doubleWithLeftChild(node_t *&k3)
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

//right child node double rotation
template <class T>
void AvlTree<T>::doubleWithRightChild(node_t *&k3)
{
    rotateWithRightChild(k3->right);
    rotateWithLeftChild(k3);
}

//balance
template <class T>
void AvlTree<T>::balance(node_t *&t)
{
}

template <class T>
void AvlTree<T>::Insert(const T &elem)
{
    Insert(elem, root);
}

template <class T>
void AvlTree<T>::Insert(const T &elem, node_t *&t)
{
    if (t == nullptr)
    {
        t = new node_t(elem);
    }
    else if (t->val > elem)
    {
        Insert(elem, t->left);
    }
    else if (t->val < elem)
    {
        Insert(elem, t->right);
    }
    balance(t);
}

template <class T>
void AvlTree<T>::Remove(const T &elem)
{
    Remove(elem, root);
}

template <class T>
void AvlTree<T>::Remove(const T &elem, node_t *&t)
{
    if (t == nullptr)
        return;
    if (t->val > elem)
        Remove(elem, t->left);
    else if (t->val < elem)
        Remove(elem, t->right);
    else if (t->left != nullptr && t->right != nullptr)
    {
        t->val = FindMin(t->right)->val;
        Remove(t->val, t->right);
    }
    else
    {
        node_t *oldNode = t;
        t = t->left == nullptr ? t->left : t->right;
        delete oldNode;
    }
    balance(t);
}

template <class T>
bool AvlTree<T>::Contains(const T &elem) const
{
}

template <class T>
void AvlTree<T>::Traversal()
{
}
