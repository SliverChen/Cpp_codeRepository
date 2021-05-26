/*
    Topic:  min Days
    Author: Sliverchen
    Create file date : 2021 / 5 / 9
    Explanation:

*/

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    if (m * k > n) //如果所需花朵大于花园中的花朵，则直接返回-1
        return -1;

    vector<int> temp = bloomDay;
    sort(temp.begin(), temp.end());

    vector<int> dayThrough(n, 0); //记录bloomDay中出现的花开的日期
    int size = 0;
    for (auto value : temp) //排序并去重
    {
        if (dayThrough[size - 1] == value && size != 0)
            continue;
        else
        {
            dayThrough[size] = value;
            size++;
        }
    }

    vector<int> bloom(n, 0); //用于记录是否花开

    return -1;
}