/*
    Topic : Binary Search Achieve
    Author : Sliverchen
    Create file date ： 2021 / 4 / 26

    Explanation:
        before calling the Binary Search function, we should make sure that the array is sorted from small to big
        this code will achieve three kinds of binary search, where are aim at:
            1) finding the input element;  //this will find the input element closely to the middle
            2) finding the left edge of the input element; (etc: [1,2,3,3,4],target = 3 ----->  [Out]:2)
            3) finding the right edge of the input element (etc: [1,2,3,3,4],target = 3 ----->  [Out]:3)
    
    Key:
        while coping the edge, we should pay attention about what value should we set for the left / right
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//achieve function of finding the input target
int BinarySearch(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (target < nums[mid])
            right = mid - 1;
        else if (target == nums[mid])
            return mid;
        else if (target > nums[mid])
            left = mid + 1;
    }
    return -1;
}

//achieve function of finding the left edge of the input target
int BinarySearch_leftBound(vector<int> &nums, int target)
{
    int left = 0, right = nums.size(), mid;
    while (left < right)
    {
        mid = (left + right) >> 1;
        if (target <= nums[mid])
            right = mid;
        else if (target > nums[mid])
            left = mid + 1;
    }
    return right;
}

//achieve function of finding the right edge of the input target
int BinarySearch_rightBound(vector<int> &nums, int target)
{
    int left = 0, right = nums.size(), mid;
    while (left < right)
    {
        mid = (left + right) >> 1;
        if (target < nums[mid])
            right = mid;
        else if (target >= nums[mid])
            left = mid + 1;
    }
    return left - 1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 6, 7, 8, 9, 10};
    printf("the edge of the index of the array is [%d,%d]\n", 0, nums.size() - 1);
    cout << BinarySearch(nums, 4) << endl;
    cout << BinarySearch_leftBound(nums, 4) << endl;
    cout << BinarySearch_rightBound(nums, 4) << endl;
    system("pause");
    return 0;
}
