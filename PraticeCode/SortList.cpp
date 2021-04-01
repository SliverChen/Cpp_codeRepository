/*
    Topic: Implement ordered list
    Statement:
        while inserting element, sort the list
        while deleting element, no need to sort(because doing at the sorted list)
*/

#include <iostream>
using namespace std;

template <class T>
struct linkNode
{
    T val;
    linkNode<T> *next;
    linkNode()
    {
        val = T();
        next = NULL;
    }

    linkNode(T value)
    {
        val = value;
        next = NULL;
    }
};

template <class T>
class sortList
{
public:
    sortList()
    {
        head = NULL;
        size = 0;
    }

    void insert(T element)
    {
        linkNode<T> *newNode = new linkNode<T>(element);
        linkNode<T> *curNode = head->next;

        if (curNode->val > element) //if head->next->val is bigger than element, we should put the headNode next to the newNode
        {
            head->next = curNode->next;
            curNode->next = newNode;
            return;
        }

        while (curNode != NULL && curNode->val <= element)
        {
            curNode = curNode->next;
        }
        if (curNode->next != NULL)
        {
            newNode->next = curNode->next;
            curNode->next = newNode;
        }
        else
        {
            curNode->next = newNode;
        }
    }

private:
    int size;
    linkNode<T> *head;
};

int main()
{
    sortList<int> list;
    list.insert(3);
    list.insert(2);
}