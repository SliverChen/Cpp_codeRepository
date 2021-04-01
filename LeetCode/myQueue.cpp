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


#define MAXCAPACITY 100

template<class T>
class MyQueue
{
    public:
        MyQueue()
        {
            front = elements;
            tail = elements;
        }

        bool enQueue(T element)
        {
            if(tail == &elements[MAXCAPACITY])
            {
                printf("the array is out of range, which the Max capacity is %d\n",MAXCAPACITY);
                return false;
            }
            *tail = element;
            tail++;
            return true;
        }

        bool deQueue()
        {
            if(front == tail)
            {
                printf(" the queue is empty, which can't do this operation");
                return false;
            }

            front--;
            return true;
        }

        bool isEmpty()
        {
            return front == tail;
        }

        int getSize()
        {
            return tail - front;
        }

        T getFront()
        {
            return *front;
        }

    private:
        T elements[MAXCAPACITY];
        T *front;
        T *tail;
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
    cout << myQueue.getFront() << endl;
    myQueue.deQueue();
    cout << myQueue.getFront() << endl;
    system("pause");
    return 0;
}