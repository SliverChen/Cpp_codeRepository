/*
    Topic: Merge Sort
    Statement:
        using Dividing and conquer to implement this algorithm
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    vector<int> arr = {4, 3, 2, 1};
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    MergeSort(arr, 0, arr.size() - 1);
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");
    system("pause");
    return 0;
}