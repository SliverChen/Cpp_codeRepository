/*
    Topic: Shell Sort
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int> &arr)
{
    int j;
    bool flag;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] > arr[i])
        {
            flag = true;
            j = i - 1;
            swap(arr[i - 1], arr[i]);
            while (flag && j - 1 >= 0)
            {
                if (arr[j - 1] > arr[j])
                {
                    swap(arr[j - 1], arr[j]);
                    j = j - 1;
                }
                else
                    flag = false;
            }
        }
    }
}

void ShellSort(vector<int> &arr)
{
    //从小到大
    int delta = 0;

    int n = arr.size();
    while (delta < n / 2)
        delta = 2 * delta + 1;

    while (delta >= 1)
    {
        for (int i = 0; i < ceil((double)n / (double)delta); i++) //遍历每组并对每组进行一次插入排序
        {
            for (int k = i + delta; k < n; k += delta)
            {
                int j = k;
                while (arr[j] < arr[j - delta] && j - delta >= 0)
                {
                    swap(arr[j], arr[j - delta]);
                    j -= delta;
                }
            }
        }
        delta = delta / 2;
    }
}

int main()
{
    vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printf("the previous array is as follows:\n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    ShellSort(arr);

    printf("after shell sort, the array is as follows:\n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    system("pause");
    return 0;
}