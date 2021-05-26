#include <iostream>
using namespace std;

void reverseArr(int *&arr, int m, int n)
{
    int arrLength = m + n;
    //简单一点，我们开辟一个新的内存空间存储数组a
    //然后将数组b的值从0开始存放，最后再将数组a的值从数组b之后存放
    int *arr_a = new int[m];
    for (int i = 0; i < m; i++)
    {
        arr_a[i] = arr[i];
    }

    //将刷新arr前n个元素替换为数组b的值
    for (int i = 0, j = m; i < n, j < arrLength; i++, j++)
    {
        arr[i] = arr[j];
    }

    for (int i = n, j = 0; i < arrLength; i++, j++)
    {
        arr[i] = arr_a[j];
    }
}

int main()
{
    int *arr = new int[6]{1, 2, 3, 4, 5, 6};
    reverseArr(arr, 2, 4);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}