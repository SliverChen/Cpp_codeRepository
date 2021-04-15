/*
    Topic: Insert sort
*/

#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int> &arr)
{
    bool flag;
    int j;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            swap(arr[i], arr[i - 1]);
            flag = true;
            j = i - 1;
            while (flag && j - 1 >= 0)
            {
                if (arr[j] < arr[j - 1])
                {
                    swap(arr[j], arr[j - 1]);
                }
                else
                    flag = false;
            }
        }
    }
}

int main()
{
    vector<int> arr = {5, 2, 2, 3, 8};
    printf("the previous array is as follows:\n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    InsertSort(arr);

    printf("after insert Sort, the array is as follows:\n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");
    system("pause");
    return 0;
}