/*
    Topic: Shell Sort
*/

#include <iostream>
#include <vector>
using namespace std;

void ShellSort(vector<int> &arr)
{
}

int main()
{
    vector<int> arr = {5, 2, 2, 3, 8};
    printf("the previous array is as follows:\n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    ShellSort(arr);

    printf("after shell sort, the array is as follows:\n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    system("pause");
    return 0;
}