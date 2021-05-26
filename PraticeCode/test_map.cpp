/*
    Topic: STL的map使用
    Author:Sliverchen
    Craete file date : 2021 / 5 / 23
    Explanation:
        首先我们知道map是具有有序性的数据以键值对存储的数据结构
        与unordered_map最大的不同就是map在插入之后保持它的键有序性
        因此我们在进行insert的时候
        就算插入的键是无序的
        利用迭代器我们可以遍历它的有序键序列
        如果插入的键存在重复项，我们可以利用find判断当前map中是否存在以该值为键的键值对
        注意find函数返回的是迭代器，是否存在我们只需判断返回的迭代器是否为map.end()即可

*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> ordered_map;
    ordered_map.insert(pair<int, int>{-10, 1});
    ordered_map.insert(pair<int, int>{5, 1});
    ordered_map.insert(pair<int, int>{1, 1});
    ordered_map.insert(pair<int, int>{4, 1});
    ordered_map.insert(pair<int, int>{6, 1});
    ordered_map.insert(pair<int, int>{2, 1});
    ordered_map.insert(pair<int, int>{8, 1});

    if (ordered_map.find(4) != ordered_map.end())
        ordered_map[4]++;
    map<int, int>::iterator it = ordered_map.begin();

    while (it != ordered_map.end())
    {
        printf("%d->%d\n", it->first, it->second);
        it++;
    }
    system("pause");
    return 0;
}