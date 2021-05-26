#include "Graph.cpp"

int main()
{
    int matrix[][3] = {
        {1, 2, 5},
        {2, 3, 3},
        {3, 2, 3},
        {3, 1, 1},
        {5, 2, 3},
        {1, 4, 4}};
    Graph_AdjacencyList<int> myGraph;
    myGraph.CreateGraph(matrix, 6);
    cout << myGraph.getNodeIn(1) << endl;
    cout << myGraph.getNodeOut(1) << endl;
    system("pause");
    return 0;
}