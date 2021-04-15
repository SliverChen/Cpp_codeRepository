/*
    Topic: Shell Sort
*/

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
    int delta = arr.size() / 2;
    while (delta > 0)
    {
        if (delta == 1)
        {
            InsertSort(arr);
            break;
        }
        for (int i = 0; i < arr.size() - delta; i++)
        {
            if (arr[i] > arr[i + delta])
            {
                swap(arr[i], arr[i + delta]);
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