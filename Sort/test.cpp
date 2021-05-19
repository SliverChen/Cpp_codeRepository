
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &nums, vector<int> &temp, int left, int right)
{
    //拆分终止条件  （left == right 就行）
    if (left >= right)
        return;

    //拆分
    int mid = (left + right) >> 1;
    mergeSort(nums, temp, left, mid);
    mergeSort(nums, temp, mid + 1, right);

    //合并
    int i = left, j = mid + 1, k = left; //i是左边数组的起始索引，j是右边数组的起始索引，k是这两个数组合并后的起始索引
    while (i <= mid && j <= right)
    {
        //下面的操作是将两个数组较小者先放到临时数组中
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    //将两个数组中剩余的部分依次放入临时数组中（注意到这里的前提是两个数组的剩余元素是有序的
    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= right)
        temp[k++] = nums[j++];

    //将临时数组中对于这两个数组的位置的修改同步到原数组中
    for (i = left; i <= right; i++)
        nums[i] = temp[i];
}

int main()
{
    vector<int> nums = {8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> temp_nums(nums.size(), 0);
    mergeSort(nums, temp_nums, 0, nums.size() - 1);
    for (auto value : nums)
        cout << value << " ";
    cout << endl;
    system("pause");
    return 0;
}