#include <iostream>
using namespace std;

void reverse(int *&arr, int length)
{
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int *arr = new int[5]{1, 2, 3, 4, 5};
    int *arr2 = new int[4]{1, 2, 3, 4};
    reverse(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");
    reverse(arr2, 4);
    for (int i = 0; i < 4; i++)
        printf("%d ", arr2[i]);
    printf("\n");
    system("pause");
    return 0;
}