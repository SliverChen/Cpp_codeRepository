/*
author:SliverChen
email: SliverCChen@163.com

    Title: implement maximum heap
    Statement:
    1、when inserting, 
        1)the inserting element will be firstly inserted at the end of the heap and then contrast with its parent node
        2)if it is bigger than its parent node, reverse their site, it's not finish until the inserting element is in the suitable site.

    2、this code we will use two way to implement the maximum heap
        1)first： the data structure is list
        2)second: the data structure is vector
*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
struct HeapNode
{
    T val;
    HeapNode<T> *next;
};

template <class T>
class MaxHeap
{
public:
    virtual bool push(T elem) { return true; }
    virtual bool pop(T elem) { return true; }
    virtual T getMin() { return T(); }
    virtual int getIndex(const T &elem) { return -1; }
    bool isEmpty()
    {
        return size == 0;
    }

protected:
    int size;
};

/*
    while using vector, we should know that what index of parent root and child root
    example:
        a root which index is i:
        the index of its parent root is floor((i+1)/2)-1
        the index of its left child root is 2*(i+1)-1
        the index of its right child root is 2*(i+1)
*/
template <class T>
class MaxHeap_Vector : public MaxHeap<T>
{
public:
    MaxHeap_Vector()
    {
        size = 0;
    }
    MaxHeap_Vector(vector<T> array)
    {
    }

    bool push(T element)
    {
        elements.push_back(element);
        size++;
        upFilter(size - 1);
        return true;
    }

    bool pop()
    {
        swap(elements[0], elements[size - 1]);
        elements.pop_back();
        size--;
        downFilter(0);
        return true;
    }

    T getMin()
    {
        int minIndex = 0;
        for (int i = 1; i < size; i++)
        {
            if (elements[minIndex] > elements[i])
            {
                minIndex = i;
            }
        }
        return elements[minIndex];
    }

    int getIndex(const T &elem)
    {
        for (int i = 0; i < size; i++)
        {
            if (elements[i] == elem)
            {
                return i;
            }
        }
        return -1;
    }

    void printHeap()
    {
        for (auto elem : elements)
        {
            printf("%d ", elem);
        }
        printf("\n");
    }

private:
    vector<T> elements;
    int size;
    void upFilter(int curIndex)
    {
        if (curIndex == 0)
            return;
        int parentIndex = floor(curIndex / 2 + 1) - 1;
        if (elements[curIndex] < elements[parentIndex])
        {
            return;
        }
        swap(elements[curIndex], elements[parentIndex]);
        upFilter(parentIndex);
    }

    void downFilter(int curIndex)
    {
        if (curIndex == size - 1)
            return;
        int leftchildIndex = 2 * (curIndex + 1) - 1;
        int rightchildIndex = 2 * (curIndex + 1);
        int biggerIndex;
        if (leftchildIndex > size - 1)
            return;
        else if (rightchildIndex > size - 1)
            biggerIndex = leftchildIndex;
        else
            biggerIndex = elements[leftchildIndex] > elements[rightchildIndex] ? leftchildIndex : rightchildIndex;
        if (elements[curIndex] < elements[biggerIndex])
        {
            swap(elements[curIndex], elements[biggerIndex]);
            downFilter(biggerIndex);
        }
        else
            return;
    }
};

int main()
{
    MaxHeap_Vector<int> myheap;
    myheap.push(2);
    myheap.push(4);
    myheap.push(1);
    myheap.push(5);
    myheap.push(6);
    myheap.push(3);
    myheap.printHeap();

    myheap.pop();
    myheap.printHeap();

    myheap.pop();
    myheap.printHeap();

    system("pause");
    return 0;
}