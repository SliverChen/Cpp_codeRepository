/*
    Topic: find the element a,b,c which they plus equals zero
    statement:
        1)how to find the three elements which is entertain the requirement
        2)how to make the three elements distinctive(not exist two vector which has radical component)
        3)we should know that one element can be used mutiple times
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findThreeNums(vector<int> &nums)
{
    vector<vector<int>> result;
    if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2)
        return result;
    int index = 0;
    //find the a,b,c
    vector<int> temp;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sort(temp.begin(), temp.end());
                    for (auto array : result)
                    {
                        if (array == temp)
                        {
                            temp.clear();
                            goto Couter;
                        }
                    }
                    result.push_back(temp);
                    temp.clear();
                }
            Couter:;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> datas = {1, 2, 3, 4, -1, -2, 0, -3, -4};
    vector<vector<int>> result = findThreeNums(datas);
    int index = 1;
    for (auto array : result)
    {
        printf("the %d array is :", index);
        for (auto value : array)
        {
            printf("%d ", value);
        }
        printf("\n");
        index++;
    }
    system("pause");
    return 0;
}