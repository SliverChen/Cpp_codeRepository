/*
    Topic: Tong Sort
*/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void TongSort(vector<int> &arr)
{
}

int main()
{
    //引入：随机输入多个0-1000之间的整数，并将它们按从小到大进行排序
    int nums[1001];
    memset(nums, 0, sizeof(nums));
    int num;
    while (cin >> num)
    {
        nums[num]++;
        if (cin.get() == '\n')
            break;
    }
    int count;
    for (int i = 0; i < 1001; i++)
    {
        count = 0;
        while (nums[i] - count != 0)
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
    system("pause");
    return 0;
}