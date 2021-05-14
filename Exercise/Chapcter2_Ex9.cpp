#include <iostream>
using namespace std;

void binarySearch(int *&arr, int &length, int left, int right, int x)
{
    //利用二分法的思路实现用最少时间在有序线性表中找到x
    //注意找到后需要跟后继元素进行交换操作
    //找不到则需要将x插入到线性表中并且保持有序状态
    //假设线性表从左到右递增
    if (left > right)
    {
        length = length + 1;
        realloc(arr, length * sizeof(arr[0]));
        for (int i = length - 1; i > left; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[left] = x;
        return;
    }

    int mid = (left + right) >> 1;
    if (arr[mid] < x)
    {
        binarySearch(arr, length, mid + 1, right, x);
    }
    else if (arr[mid] > x)
    {
        binarySearch(arr, length, left, mid - 1, x);
    }
    else if (arr[mid] == x)
    {
        swap(arr[mid], arr[mid + 1]);
        return;
    }
}

int main()
{
    int *arr = new int[8]{1, 2, 4, 6, 7, 8, 10, 12};
    int length = 8;
    binarySearch(arr, length, 0, length - 1, 2);
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}