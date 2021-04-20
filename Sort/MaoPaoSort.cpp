/*
    Topic:  MaoPao Sort
*/

#include <iostream>
#include <vector>
using namespace std;

void MaoPaoSort(vector<int> &arr, bool isUpandDown)
{
    int times = 0;
    if (isUpandDown)
    {
        //从大到小排时每次都会将该次循环中的最小值定到末尾
        while (times < arr.size() - 1)
        {
            for (int i = 0; i < arr.size() - 1; i++)
            {
                if (arr[i] < arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                }
            }
            times++;
        }
    }
    else
    {
        //从小到大排时每次都会将该次循环中的最大值定到末尾
        while (times < arr.size() - 1)
        {
            for (int i = 0; i < arr.size() - 1; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                }
            }
            times++;
        }
    }
}

int main()
{
    vector<int> arr = {5, 3, 2, 2, 8};
    printf("previous array is as follows: \n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");
    MaoPaoSort(arr, false);
    printf("after MaoPao Sort Down and up, the array is as follows:\n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    printf("after MaoPao Sort Up and Down, the array is as follows:\n");
    MaoPaoSort(arr, true);
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    system("pause");
    return 0;
}