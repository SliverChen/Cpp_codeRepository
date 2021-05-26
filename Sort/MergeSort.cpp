/*
    Topic: Merge Sort
    Statement:
        using Dividing and conquer to implement this algorithm
        这种方法过于复杂了，复看的时候难懂
        下面介绍一种类似与二叉树的后序遍历的操作
        在遍历完左右子树之后进行合并操作，原理就等同于归并排序的思路
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*************生涩难懂版本*******************************************/
//first implement how to merge two sorted array
vector<int> MergeArray(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> resultArray;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            resultArray.push_back(arr1[i]);
            i++;
        }
        else
        {
            resultArray.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size())
    {
        resultArray.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size())
    {
        resultArray.push_back(arr2[j]);
        j++;
    }
    return resultArray;
}

void Merge_Array(vector<int> &arr, int left_start, int left_end, int right_start, int right_end)
{
    int i = left_start, j = right_start;
    printf("In merge_Array: between %d and %d,doing mergeArray\n", left_start, right_end);
    printf("the left arr edge is: [%d,%d], the right arr edge is: [%d,%d]\n", left_start, left_end, right_start, right_end);
    vector<int> tempArr;
    while (i <= left_end && j <= right_end)
    {
        if (arr[i] < arr[j])
        {
            tempArr.push_back(arr[i]);
            i++;
        }
        else
        {
            tempArr.push_back(arr[j]);
            j++;
        }
    }
    while (i <= left_end)
    {
        tempArr.push_back(arr[i]);
        i++;
    }
    while (j <= right_end)
    {
        tempArr.push_back(arr[j]);
        j++;
    }

    int startIndex = left_start;
    for (auto value : tempArr)
    {
        printf("make arr[%d] equals %d\n", startIndex, value);
        arr[startIndex++] = value;
    }
}

void MergeSort(vector<int> &arr, int left, int right)
{
    printf("between %d and %d, doing MergeSort\n", left, right);
    if (left >= right)
        return;
    int middle = (left + right) >> 1;
    if (left < middle)
    {
        MergeSort(arr, left, middle - 1);
        MergeSort(arr, middle, right);
        Merge_Array(arr, left, middle - 1, middle, right);
    }
    else
    {
        MergeSort(arr, left, middle);
        MergeSort(arr, middle + 1, right);
        Merge_Array(arr, left, middle, middle + 1, right);
    }
}

/************优化逻辑版本**************************************/
void mergeSort_Opt(vector<int> &arr, vector<int> &temp, int left, int right)
//采用一个temp的临时数组，大小与arr相同
{
    if (left >= right)
        return;

    //拆分操作
    int mid = (left + right) >> 1;
    mergeSort_Opt(arr, temp, left, mid);
    mergeSort_Opt(arr, temp, mid + 1, right);

    //合并操作
    int i = left, j = mid + 1, k = left; //i是左边数组的起始索引，j是右边数组的起始索引，k是合并数组的起始索引
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j]) //保持稳定性，这里加上等号，确保相等的值不改变它的相对位置
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    //将左边数组剩余部分依次放到临时数组中，这里的前提是左边数组剩余部分已经有序
    while (i <= mid)
        temp[k++] = arr[i++];

    //将右边数组剩余部分依次放到临时数组中，同上
    while (j <= right)
        temp[k++] = arr[j++];

    //将临时数组中[left,right]的值更新到原数组arr中
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

int main()
{
    vector<int> arr = {8, 7, 6, 5, 4, 3, 2, 1};
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    vector<int> temp(arr.size());
    mergeSort_Opt(arr, temp, 0, arr.size() - 1);
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");
    system("pause");
    return 0;
}