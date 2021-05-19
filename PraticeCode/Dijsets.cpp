#include "Dijsets.h"
#include <iostream>
DisjointSets::DisjointSets(int size)
{
    nodes.resize(size);
    for (auto &value : nodes)
        value = -1;
}

int DisjointSets::Find(int node) const
{
    if (nodes[node] < 0)
        return node;
    return Find(nodes[node]);
}

int DisjointSets::Find_Comprass(int node)
{
    if (nodes[node] < 0)
        return node;
    return nodes[node] = Find_Comprass(nodes[node]);
}

void DisjointSets::Union_normal(int root1, int root2)
{
    nodes[root2] = root1;
}

void DisjointSets::Union_rank(int root1, int root2)
{
    if (nodes[root2] < nodes[root1]) //如果root1的高度比root2的大，root2是根，此时将root1并在root2下
        nodes[root1] = root2;
    else //如果root1的高度不超过root2
    {
        if (nodes[root1] == nodes[root2]) //如果高度相等则使root1的高度-1
            --nodes[root1];
        nodes[root2] = root1; //让root1成为新的根
    }
}

void DisjointSets::printNodes()
{
    for (auto value : nodes)
        printf("%d ", value);
    printf("\n");
}