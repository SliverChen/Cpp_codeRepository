#include <iostream>
using namespace std;

template <class T>
void delMin(T *&arr, int &length, T &minEle)
{
    if (length == 0)
    {
        printf("the array is empty\n");
        return;
    }
    T min = arr[0];
    int index = 0;
    for (int i = 1; i < length; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }
    minEle = min;
    swap(arr[index], arr[length - 1]);
    length--;
    realloc(arr, length * sizeof(arr[0]));
}

int main()
{
    int *arr = new int[5]{2, 3, 4, 5, 1};
    int length = 5;
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
    int minEle;
    delMin(arr, length, minEle);
    cout << minEle << endl;
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;

    system("pause");
    return 0;
}