#include <iostream>
using namespace std;

//注意题目中的顺序表是有序的，
//因此我们只需要遍历一次顺序表，
//遇到重复项的时候跳过它，并记录它的位置，
//直到遇到下一次不重复项的时候再将不重复项交换到这个位置
void delDeplicate(int *&arr, int &length)
{
    //简单一点，每次删除往前移
    for (int i = 1; i < length; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            for (int j = i; j < length - 1; j++)
            {
                swap(arr[j], arr[j + 1]);
            }
            length--;
            i--; //用于判断当前位置是否还是跟前一个值重复
        }
    }
}

int main()
{
    int *arr = new int[8]{1, 2, 3, 4, 4, 5, 5, 6};
    int length = 8;
    delDeplicate(arr, length);
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}