/*
    Topic: Heap Sort
    Statement: 
        it can be solved by two ways:

        1) indirectly using heap data structure(MAX or MIN whatever u like): 
            put element into heap, get the top one, pop it and recycle this process

        2) utilize the idea of up and down filtration inside the heap replace of the way one(this can be more concise)
            Totally, it can be seperated as two steps:
                1: make a disordered vector change into (ordered) maximum heap / minimum heap
                2: imitate the pop function inside heap
*/

#include "myHeap.h"

/***************the first way***********************/

void HeapSort(vector<int> &arr)
{
    MaxHeap_Vector<int> myheap;
    for (auto value : arr)
    {
        myheap.push(value);
    }
    int index = 0;
    while (index < arr.size())
    {
        arr[index++] = myheap.getTop();
        myheap.pop();
    }
}

/**********************the second way**************************/

void adjustHeap(vector<int> &arr, int index, int arrLength)
{
    //this function is made for maximum heap
    int left = 2 * index + 1, right = 2 * index + 2;
    if ((index < 0 && index > arrLength) || left > arrLength)
        return;

    if (right > arrLength)
    {
        if (arr[index] < arr[left])
        {
            swap(arr[index], arr[left]);
        }
    }
    else
    {
        if (arr[left] > arr[index] && arr[left] > arr[right])
        {
            swap(arr[index], arr[left]);
            adjustHeap(arr, left, arrLength);
        }
        else if (arr[right] > arr[index] && arr[right] > arr[left])
        {
            swap(arr[index], arr[right]);
            adjustHeap(arr, right, arrLength);
        }
    }
}

void MakeHeap(vector<int> &arr)
{
    int n = arr.size();
    //the index of the last none-leaf node is  arr.Length / 2 - 1

    /*
    *   the index (arr.Length - 1) / 2 - 1 is the last none-leaf full node
    */

    //we should begin at the last none-leaf node to configure if the structure should be adjusted
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        adjustHeap(arr, i, n - 1);
    }
}

void HeapSort2(vector<int> &arr)
{
    //instruct heap
    MakeHeap(arr);

    // imitate the pop function inside the heap
    // every time imitating pop funtion,the range of adjusting heap will decrease one unit's length
    int length = arr.size() - 1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        length--;
        adjustHeap(arr, 0, length);
    }
}

int main()
{

    vector<int> arr = {5, 2, 1, 3, 8};

    printf("array1: \n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");
    HeapSort(arr);
    printf("by using way one, the sorted array is as follows: \n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n\n");

    printf("array 2:\n");
    for (auto value : arr)
    {

        printf("%d ", value);
    }
    printf("\n");
    HeapSort2(arr);
    printf("by using way two, the sorted array is as follows:\n");
    for (auto value : arr)
    {
        printf("%d ", value);
    }
    printf("\n");

    system("pause");
    return 0;
}