#include "myAvlTree.cpp"
int main()
{
    AvlTree<int> myAvlTree;
    myAvlTree.Insert(5);
    myAvlTree.Insert(3);
    myAvlTree.Insert(6);
    myAvlTree.Insert(1);
    myAvlTree.Insert(4);
    myAvlTree.Insert(2);

    myAvlTree.Traversal(1);

    myAvlTree.Traversal(2);
    system("pause");
    return 0;
}