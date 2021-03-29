/*
author:SliverChen
email: SliverCChen@163.com

Title: 实现最大堆
*/

#include<iostream>
#include<vector>

using namespace std;

template<class T>
struct HeapNode
{
    T val;
    HeapNode<T> *next;
};

template<class T>
class MaxHeap
{
    public:
        MaxHeap()
        {
            head->next = NULL;
            size = 0;
        }

        bool push(T element)
        {
            //....
            size++;
            return true;
        }

        T getTopElem()
        {
            return head->val;
        }
 
        bool pop()
        {
            //...
            size--;
            return true;
        }

        bool isEmpty()
        {
            return size == 0;
        }
        
        void sortHeap()
        {

        }

    private:
        HeapNode<T> *head;
        int size;
};

int main()
{
    HeapNode<int> myHeap;
    system("pause");
    return 0;
}