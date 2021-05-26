/*
    Topic: Implement Stack data structure
    Statement:
        there are two data structure can be used to achieve the infrastructure of the stack:
            1) vector(continuous address)
            2) list  (discontinuous address)
    this code will show two of them how to implement the stack storage structure
*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <class T>
class myStack //abstract class
{
public:
    bool isEmpty()
    {
        return size == 0;
    }
    virtual void push(T element) = 0;
    virtual void pop() = 0;
    virtual T getTop() = 0;
    virtual void printStack() = 0;
    int size;
};

template <class T>
class myVector_Stack : public myStack<T> //inherited class
{
public:
    myVector_Stack()
    {
        size = 0;
    }

    void push(T element)
    {
        elements.push_back(element);
        size++;
    }

    void pop()
    {
        elements.pop_back();
        size--;
    }

    T getTop()
    {
        return elements[size - 1];
    }

    void printStack()
    {
        for (int i = elements.size() - 1; i >= 0; i--)
        {
            printf("%d\n", elements[i]);
        }
    }

private:
    vector<T> elements;
    int size;
};

template <class T>
class myList_Stack : public myStack<T> //inherited class
{
public:
    myList_Stack()
    {
        size = 0;
    }

    void push(T element)
    {
        elements.push_back(element);
        size++;
    }

    void pop()
    {
        elements.pop_back();
        size--;
    }

    T getTop()
    {
        return *elements.rbegin();
    }

    void printStack()
    {
        for (auto iter = elements.rbegin(); iter != elements.rend(); iter++)
        {
            printf("%d \n", *iter);
        }
    }

private:
    list<T> elements;
    int size;
};

int main()
{
    myVector_Stack<int> stack1;
    printf("create a stack achieving in vector.\n");
    stack1.push(4);
    stack1.push(3);
    stack1.push(5);
    stack1.push(6);
    stack1.push(1);
    printf("get stack1's top :%d\n", stack1.getTop());
    printf("print stack1:\n");
    stack1.printStack();

    stack1.pop();
    printf("after doing pop one time, the stack1 is as follows: \n");
    stack1.printStack();

    printf("create a stack achieveing in list.\n");
    myList_Stack<int> stack2;
    stack2.push(7);
    stack2.push(12);
    stack2.push(6);
    stack2.push(2);
    printf("get stack2's top: %d\n", stack2.getTop());
    printf("print stack2:\n");
    stack2.printStack();

    stack2.pop();
    printf("after doing pop one time, the stack2 is as follows: \n");
    stack2.printStack();
    system("pause");
    return 0;
}
