/*
    Achieve the function that in the graph
*/

#include "Graph.h"

/*******************Graph_AdjacencyList***************************/

template <class T>
void Graph_AdjacencyList<T>::CreateGraph(T matrix[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        T from = matrix[i][0];
        T to = matrix[i][1];
        T weight = matrix[i][2];
        if (nodes.find(from) == nodes.end()) //等效于如果找不到from这个点  map.find()函数找不到时会返回end()迭代器
        {
            nodes[from] = new Node<T>(from); //map中如果没有from这个点，根据[]的特性会新创建索引为from的键然后再进行赋值操作
        }

        if (nodes.find(to) == nodes.end()) //等效于如果找不到to这个点
        {
            nodes[to] = new Node<T>(to);
        }

        Node<T> *fromNode = nodes[from];
        Node<T> *toNode = nodes[to];

        Edge<T> *newedge = new Edge<T>(fromNode, toNode, weight);
        fromNode->nexts.push_back(toNode);
        fromNode->out++;
        fromNode->edges.push_back(newedge);

        toNode->in++;

        edges.insert(newedge);
    }
}

template <class T>
int Graph_AdjacencyList<T>::getNodeIn(int No)
{
    if (nodes.find(No) == nodes.end()) //如果找不到No，则返回-1
        return -1;
    return nodes[No]->in;
}

template <class T>
int Graph_AdjacencyList<T>::getNodeOut(int No)
{
    if (nodes.find(No) == nodes.end())
        return -1;
    return nodes[No]->out;
}

template <class T>
void Graph_AdjacencyList<T>::addEdge(int from, int to, T val)
{
    int a = 1;
}

template <class T>
void Graph_AdjacencyList<T>::delEdge(int from, int to)
{
    int a = 1;
}

template <class T>
bool Graph_AdjacencyList<T>::findEdgeByNodes(int from, int to)
{
    return false;
}

template <class T>
bool Graph_AdjacencyList<T>::findEdgeByWeights(T val)
{
    return false;
}

/**************************************************************/

/****************Grapah_AdjacencyMatrix********************/

template <class T>
Graph_AdjacencyMatrix<T>::Graph_AdjacencyMatrix()
{
    edges.resize(DEFAULT_SIZE);
    for (auto row : edges)
    {
        row.resize(DEFAULT_SIZE);
        for (auto elem : row)
            elem = 0;
    }
}

template <class T>
Graph_AdjacencyMatrix<T>::Graph_AdjacencyMatrix(int size)
{
    edges.resize(size);
    for (auto row : edges)
    {
        row.resize(size);
        for (auto elem : row)
            elem = 0;
    }
}

template <class T>
void Graph_AdjacencyMatrix<T>::addEdge(int from, int to, T val)
{
    edges[from][to] = val;
}

template <class T>
void Graph_AdjacencyMatrix<T>::delEdge(int from, int to)
{
    edges[from][to] = 0;
}

template <class T>
bool Graph_AdjacencyMatrix<T>::findEdgeByNodes(int from, int to)
{
    return edges[from][to] == 0;
}

template <class T>
bool Graph_AdjacencyMatrix<T>::findEdgeByWeights(T val)
{
    for (auto row : edges)
        for (auto columns : row)
            if (columns == val)
                return true;
    return false;
}