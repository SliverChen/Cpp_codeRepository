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
        for (auto array : bucket)
        {
            array.clear();
        }
    }
}

int main()
{
    vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
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