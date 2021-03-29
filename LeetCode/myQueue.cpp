/*
author: SliverChen
email:  SliverCChen@163.com
Topic:  优先队列实现（利用数组实现）
Statement:
    队头出队 队尾入队
    需要设置两个指针对数组进行指向
*/

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class MyQueue
{
    public:
        MyQueue()
        {
            front = &elements[0];
            tail = &elements[0];
            
        }

        bool enQueue(T element)
        {
            
            return true;
        }

        bool deQueue()
        {
            
            return true;
        }

        bool isEmpty()
        {
            return elements.size() == 0;
        }

        int getSize()
        {
            return elements.size();
        }

        T front()
        {
            return elements[0];
        }

        void printQueue()
        {
            for(auto elem:elements)
            {
                printf("%d ", elem);
            }
            printf("\n");
        }

    private:
        vector<T> elements;
        int *front;
        int *tail;
};

int main()
{
    MyQueue<int> myQueue;
    myQueue.enQueue(1);
    myQueue.enQueue(2);
    myQueue.enQueue(3);
    myQueue.enQueue(4);
    myQueue.enQueue(5);
    myQueue.enQueue(6);
    myQueue.printQueue();

    system("pause");
    getchar();
    return 0;
}