/*
    Topic: Achieve circle queue
    Author: Sliverchen
    Create file date: 2021 / 4 / 27
*/

#include <iostream>
#include <vector>
using namespace std;

#define DEFAULT_CAPACITY 20

template <class T>
class CircleQueue
{
public:
    CircleQueue();
    CircleQueue(const T &capacity);
    ~CircleQueue();
    void enQueue(const T &elem);
    void deQueue();
    bool isEmpty();
    void clear();
    void printQueue();

private:
    int *head;
    int *tail;
    int size;
    int capacity;
    vector<T> elements;
};

template <class T>
CircleQueue<T>::CircleQueue()
{
    capacity = DEFAULT_CAPACITY;
    elements.resize(capacity);
    head = &elements[0];
    tail = &elements[0];
    size = 0;
}

template <class T>
CircleQueue<T>::CircleQueue(const T &capa)
{
    capacity = capa;
    elements.resize(capacity);
    head = &elements[0];
    tail = &elements[0];
    size = 0;
}

template <class T>
CircleQueue<T>::~CircleQueue()
{
    clear();
}

template <class T>
void CircleQueue<T>::enQueue(const T &elem)
{
    if (size == capacity) //这里暂时不考虑扩容的情况
        return;
    if (tail == &elements[capacity - 1]) //如果tail指向了数组的尾部，由于此时数组没有满，因此需要将tail指针移到头部
        tail = &elements[0];
    *tail = elem;
    size++;
    tail++;
}

template <class T>
void CircleQueue<T>::deQueue()
{
    if (size == 0)
        return;
    if (head == &elements[capacity - 1]) //如果head指向了数组的尾部，由此此时数组不为空，因此需要将head指针移到数组头部
        head = &elements[0];
    else
        head++;
    size--;
}

template <class T>
void CircleQueue<T>::printQueue()
{
    if (size == 0)
        return;
    for (auto index = head; index != tail; index++)
        printf("%d ", *index);
    printf("\n");
}

template <class T>
bool CircleQueue<T>::isEmpty()
{
    return size == 0;
}

template <class T>
void CircleQueue<T>::clear()
{
    size = 0;
    head = &elements[size];
    tail = &elements[size];
}

int main()
{
    CircleQueue<int> myQueue;
    myQueue.enQueue(2);
    myQueue.enQueue(3);
    myQueue.printQueue();
    system("pause");
    return 0;
}
