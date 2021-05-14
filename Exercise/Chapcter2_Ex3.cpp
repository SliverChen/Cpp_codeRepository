#include <iostream>
using namespace std;

/*
    问题：
        在遍历的同时我们需要找到值为x的元素
        并且由于这个数据结构是顺序表，因此我们需要在删除之后需要将当前位置之后的元素往前移
        但是如果我们在找到的同时进行往前移的操作，那么我们无法保证时间复杂度在O(n)之内

    解决：
        我们可以在找到第一个值为x的元素之后进行交换操作，然后记录当前位置的后一位（因为已经交换了）
        下一次遇到的值为x的元素之前，都进行交换操作
        如果遇到了值为x的元素，那么就跳过它的遍历，同时之前记录过的位置更新为这个新的位置
*/

void delX(int *&arr, int &length, int x)
{
    int newPos = -1;          //初始化为-1的位置
    int swapPos = length + 1; //初始化交换后值x出现的最左的位置，用于结束遍历
    bool isFind = false;
    int newLength = length; //记录一个新的长度，在操作完之后再赋值给length
    for (int i = 0; i < length; i++)
    {
        if (!isFind && arr[i] != x) //如果还没有遇到第一个值为x的元素，则继续遍历
            continue;
        else if (arr[i] == x && !isFind) //如果是第一次遇到，则先交换，然后再记录当前位置的下一位
        {
            isFind = true;
            swap(arr[i], arr[i + 1]);
            newPos = i + 1;
            newLength--;
            i++;
        }
        else if (arr[i] != x && isFind) //如果在第一次遇到值为x的元素后遇到了不是x的元素，那么就交换newPos和当前位置的元素，并更新newPos为当前位置
        {
            swap(arr[i], arr[newPos]);
            newPos = i;
        }
        else if (arr[i] == x && isFind) //如果遇到的不是第一次了，那么就跳过这个元素，newPos不变
        {
            newLength--;
            continue;
        }
    }
    length = newLength;
}

int main()
{
    int *arr = new int[8]{1, 2, 3, 4, 5, 4, 6, 4};
    int length = 8;
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delX(arr, length, 4);

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}