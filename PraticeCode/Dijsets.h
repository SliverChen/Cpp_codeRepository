//DisjointSet class head file

#ifndef DISJOINTSETS_H
#define DISJOINTSETS_H

#include <vector>
using namespace std;
class DisjointSets
{
public:
    DisjointSets(int size);
    int Find_Comprass(int node); //路径压缩
    int Find(int node) const;
    void Union_normal(int root1, int root2); //普通求并
    void Union_rank(int root1, int root2);   //按高度求并

    void printNodes();

private:
    vector<int> nodes;
};

#endif