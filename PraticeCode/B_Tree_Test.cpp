#include "B_Tree.cpp"
#include <iostream>
using namespace std;

int main()
{
    BTree T = NULL;
    int test[18] = {35, 16, 18, 70, 5, 50, 22, 60, 13, 17, 12, 45, 25, 42, 15, 90, 30, 7};
    for (int i = 0; i < 18; i++)
        InsertBTree(T, test[i]);
    Aoprint(T, 0);
    system("pause");
    return 0;
}