/*
    Topic: Bucket Sort
*/

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int getMaxLength(const vector<int> &arr)
{
    int maxLength;
    int maxElem = INT_MIN;
    for (auto value : arr)
    {
        if (value > maxElem)
            maxElem = value;
    }
    int tempLength = 1, times = 1;
    while (true)
    {
        if (maxElem % (int)pow(10, times) != maxElem)
        {
            maxLength = times + 1;
            times++;
        }
        else
            break;
    }
    return maxLength;
}

int getNumberofDigits(int element, int NumberofDigits)
{
    if (NumberofDigits == 0)
    {
        return element % 10;
    }
    else
    {
        int tempNum = element / (int)pow(10, NumberofDigits);
        return tempNum % 10;
    }
}

void BucketSort(vector<int> &arr)
{
    vector<vector<int>> bucket(10);
    int CircleTimes = getMaxLength(arr);
    int curNum;
    vector<int> tempArr;
    for (int time = 0; time < CircleTimes; time++)
    {
        //建立映射,将值存放到映射对应的桶中
        for (auto value : arr)
        {
            curNum = getNumberofDigits(value, time);
            bucket[curNum].push_back(value);
        }
        //从编号0-9依次将桶中的数据存放到tempArr中
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < bucket[i].size(); j++)
            {
                tempArr.push_back(bucket[i][j]);
            }
        }
        //将原来的arr覆盖成tempArr
        arr = tempArr;

        //清空tempArr和bucket用于下一次的循环
        tempArr.clear();

        for (auto &array : bucket) //这里需要注意加上引用才能正常对bucket中的数组进行清空操作
        {
            array.clear();
        }
    }
}

int main()
{
    vector<int> arr = {1, 2434646, 56, 734, 5345, 456, 42, 34, 245, 64562, 3423, 44, 56, 4523, 4, 234, 7, 4723, 4, 324, 57, 4};
    printf("the previous array is as follows:\n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    BucketSort(arr);

    printf("after Tong Sort, the array is as follows:\n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    system("pause");
    return 0;
}