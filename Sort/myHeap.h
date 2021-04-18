#include <algorithm>
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

    T getTop()
    {
        return elements[0];
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

template <class T>
class MaxHeap_List : public MaxHeap<T>
{
    MaxHeap_List()
    {
        size = 0;
        root->next = NULL;
    }
    bool push(T elem)
    {

        return true;
    }
    bool pop()
    {
        return true;
    }

    void Upfilter()
    {
    }

private:
    int size;
    HeapNode<T> *root;
};