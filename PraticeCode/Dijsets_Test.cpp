#include "Dijsets.cpp"

int main()
{
    DisjointSets myDijSets(6);
    myDijSets.printNodes();

    myDijSets.Union_normal(5, 1);
    myDijSets.Union_normal(1, 2);
    myDijSets.Union_normal(2, 3);

    myDijSets.printNodes();
    myDijSets.Find_Comprass(3);
    myDijSets.printNodes();
    system("pause");
    return 0;
}