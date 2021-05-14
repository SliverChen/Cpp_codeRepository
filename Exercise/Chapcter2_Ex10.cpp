#include <iostream>
using namespace std;

void moveLeft(int *&arr, int length, int p)
{
    //前p个值需要移到后面，相当于对前p个值和后面的值进行交换操作
    //简单一点就是额外开辟一个新的内存空间先去存储前p个元素
    //时间复杂度为O(n)，空间复杂度为O(p)

    //1-2-3-4-5-6 ,p=2 --- > 3-4-5-6-1-2
    //1-2-3-4-5-6, p=4 --- > 5-6-1-2-3-4
    //利用交换操作使得空间复杂度为O(1)
    //太复杂了我不要满分了

    int *p_arr = new int[p];
    int pos = 0;

    for (int i = 0; i < p; i++)
        p_arr[i] = arr[i]; //先将前p个元素放入一个变量中

    for (int i = 0; i < length; i++)
        if (i < length - p)
            arr[i] = arr[i + p];
        else
            arr[i] = p_arr[pos++];
}

int main()
{
    int *arr1 = new int[6]{1, 2, 3, 4, 5, 6};
    int *arr2 = new int[6]{1, 2, 3, 4, 5, 6};
    moveLeft(arr1, 6, 2);
    for (int i = 0; i < 6; i++)
        cout << arr1[i] << " ";
    cout << endl;

    moveLeft(arr2, 6, 4);
    for (int i = 0; i < 6; i++)
        cout << arr2[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}