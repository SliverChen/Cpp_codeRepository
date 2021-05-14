#include <iostream>
using namespace std;

//这里默认s和t为位置，因此下标为它们的值-1

void delArea(int *&arr, int &length, int s, int t)
{
    if (s >= t || s <= 0 || t >= length + 1)
    {
        cerr << "invaild area" << endl;
        return;
    }

    int curPos = s - 1; //记录当前区域的第一个位置，用于将后面没有被删除的元素从这个位置开始交换
    for (int i = t; i < length; i++)
    {
        swap(arr[curPos], arr[i]);
        curPos++;
    }
    length = length - (t - s + 1);
}

int main()
{
    int *arr = new int[8]{1, 2, 3, 4, 5, 4, 6, 4};
    int length = 8;
    delArea(arr, length, 2, 4);
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}