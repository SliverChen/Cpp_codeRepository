/*
    Topic:  Choose Sort
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int getMinIndex(vector<int> &arr, int start, int end)
{
    int index = -1;
    int curMin = INT_MAX;
    for (int i = start; i < end; i++)
    {
        if (arr[i] < curMin)
        {
            curMin = arr[i];
            index = i;
        }
    }
    return index;
}

void ChooseSort(vector<int> &arr)
{
    int j = 0;
    while (j < arr.size())
    {
        swap(arr[j], arr[getMinIndex(arr, j, arr.size())]);
        j++;
    }
}

int main()
{
    vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    ChooseSort(arr);

    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    system("pause");
    return 0;
}