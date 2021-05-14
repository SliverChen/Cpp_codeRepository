#include <iostream>
using namespace std;

int *mergeArr(int *&arr1, int *&arr2, int arr1_length, int arr2_length)
{
    int *result = new int[arr1_length + arr2_length];
    int i = 0, j = 0;
    int size = 0;
    while (i < arr1_length && j < arr2_length)
    {
        if (arr1[i] < arr2[j]) //哪个小先进哪个
        {
            result[size] = arr1[i];
            i++;
        }
        else
        {
            result[size] = arr2[j];
            j++;
        }
        size++;
    }
    while (i < arr1_length)
        result[size++] = arr1[i++];
    while (j < arr2_length)
        result[size++] = arr2[j++];
    return result;
}

int main()
{
    int *arr1 = new int[4]{2, 3, 5, 6};
    int *arr2 = new int[3]{1, 4, 7};
    int *arr = mergeArr(arr1, arr2, 4, 3);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}