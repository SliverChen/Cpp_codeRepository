/*
    Topic:  Achieve the common graph
    Author: Sliverchen
    Create file date ： 2021 / 5 / 10
    Explanation:
        this code will achieve the graph data structure in two ways:
            one is the Adjacency list
            the other is the Adjacency matrix
    Addition:
        图分为4类：
            1、加权有向图
            2、加权无向图
            3、无权有向图
            4、无权无向图

        这里我们实现有权有向图作为参考
*/

#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
using namespace std;

//默认边数
#define DEFAULT_SIZE 10

template <class T>
class Edge;

//结点类创建
template <class T>
class Node
{
public:
    Node(int val) : value(val), in(0), out(0) {}
    int value;
    int in;
    int out;
    list<Node *> nexts;
    list<Edge<T> *> edges;
};

//边类创建
template <class T>
class Edge
{
public:
    T weight;
    Node<T> *from;
    Node<T> *to;
    Edge() {}
    Edge(Node<T> *_from, Node<T> *_to, int _weight)
        : weight(_weight), from(_from), to(_to) {}
};

//创建图的抽象类
template <class T>
class Graph
{
public:
    virtual void addEdge(int from, int to, T val) = 0;
    virtual void delEdge(int from, int to) = 0;
    virtual void CreateGraph(T matrix[][3], int n) = 0;
    virtual bool findEdgeByNodes(int from, int to) = 0;
    virtual bool findEdgeByWeights(T val) = 0;
};

//利用邻接列表实现图
template <class T>
class Graph_AdjacencyList : public Graph<T>
{
public:
    void addEdge(int from, int to, T val);
    void delEdge(int from, int to);
    void CreateGraph(T matrix[][3], int n);
    int getNodeIn(int No);
    int getNodeOut(int No);
    bool findEdgeByNodes(int from, int to);
    bool findEdgeByWeights(T val);

private:
    map<int, Node<T> *> nodes;
    set<Edge<T> *> edges;
};

//利用邻接矩阵实现图
template <class T>
class Graph_AdjacencyMatrix : public Graph<T>
{
public:
    Graph_AdjacencyMatrix();
    Graph_AdjacencyMatrix(int size);
    void addEdge(int from, int to, T val);
    void delEdge(int from, int to);
    bool findEdgeByNodes(int from, int to);
    bool findEdgeByWeights(T val);

public:
    vector<vector<T>> edges;
};
