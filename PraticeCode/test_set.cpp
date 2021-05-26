/*******************************
 * Topic: set的stl用法
 * Author:SliverChen
 * Create file date : 2021 / 5 / 24
 ******************************/

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> myset;

    for (int i = 1; i <= 5; i++)
        myset.insert(i);

    if (!myset.empty())
        cout << "myset is not empty" << endl;
    set<int>::iterator it;
    for (it = myset.begin(); it != myset.end(); it++)
        printf("%d ", *it);
    printf("\n");

    if (myset.find(4) != myset.end())
        cout << "4 is in the myset" << endl;
    else
        cout << " 4 is not in the myset" << endl;

    myset.erase(2);

    cout << "delete 2" << endl;
    for (it = myset.begin(); it != myset.end(); it++)
        printf("%d ", *it);
    printf("\n");

    myset.erase(7);
    cout << "delete 7" << endl;
    for (it = myset.begin(); it != myset.end(); it++)
        printf("%d ", *it);
    printf("\n");

    system("pause");
    return 0;
}