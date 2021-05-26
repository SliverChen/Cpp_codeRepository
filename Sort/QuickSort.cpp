/*
    Topic: Implement Quick Sort
    Statement:
        before sort,choose the way on how to get the Benchmark Number(基准数)
            way 1) choose the first element of array as Benchmark Number
            way 2) get the first, end, middle element of array and choose the median of them as Benchmark Number
    
    ----Concrete Implement check on Ipad----
*/

#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int> &array, int left, int right)
{
    printf("%d and %d QuickSort start\n", left, right);
    if (left >= right)
    {
        return;
    }

    //use the second way to choose the Benchmark Number
    int median, middle = (left + right) >> 1;
    int a = array[left];
    int b = array[middle];
    int c = array[right];
    if ((a - b) * (a - c) <= 0)
    {
        median = a;
        swap(array[left], array[right]);
    }
    else if ((b - a) * (b - c) <= 0)
    {
        median = b;
        swap(array[middle], array[right]);
    }
    else
    {
        median = c;
    }

    int i = left, j = right - 1;
    while (i <= j) //if here is  i < j, then it can not solve the situation which the array has two elements
    {
        while (array[j] >= median && i <= j) //find the value that is smaller than the median on the right half part
            j--;
        while (array[i] <= median && i <= j) //find the value that is bigger than the median on the left half part
            i++;
        if (i < j) //swap two of them
        {
            swap(array[i], array[j]);
        }
    }
    swap(array[i], array[right]);   //swap the value which index is i and the value which index is right
    QuickSort(array, left, i - 1);  //do the recursion on the left half part
    QuickSort(array, i + 1, right); //do the recursion on the right half part
}

int main()
{
    vector<int> array = {3, 1, 2, 4, 7, 6, 5};
    for (auto value : array)
    {
        printf("%d ", value);
    }
    printf("\n");
    QuickSort(array, 0, array.size() - 1);
    for (auto value : array)
    {
        printf("%d ", value);
    }
    printf("\n");

    system("pause");
    return 0;
}