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
        head = new linkNode<T>();
        size = 0;
    }

    void push(T element)
    {
        linkNode<T> *newNode = new linkNode<T>(element);
        linkNode<T> *curNode = head->next;

        if (curNode == NULL) //if list is empty
        {
            head->next = newNode;
            size++;
            return;
        }

        if (curNode->val > element) //if head->next->val is bigger than element, we should put the headNode next to the newNode
        {
            newNode->next = head->next;
            head->next = newNode;
            size++;
            return;
        }
        while (true)
        {
            if (curNode->next != NULL && curNode->next->val <= element)
            {
                curNode = curNode->next;
                continue;
            }
            else if (curNode->next == NULL)
            {
                curNode->next = newNode;
                size++;
                return;
            }
            else if (curNode->next != NULL && curNode->next->val > element)
            {
                newNode->next = curNode->next;
                curNode->next = newNode;
                size++;
                return;
            }
        }
    }

    bool popElem(T element)
    {
        linkNode<T> *curNode = head;
        while (curNode->next)
        {
            if (curNode->next->val == element)
            {
                linkNode<T> *delNode = curNode->next;
                curNode->next = curNode->next->next;
                delete delNode;
                size--;
                return true;
            }
            curNode = curNode->next;
        }
        printf("the list has no element %d\n", element);
        return false;
    }

    void printList()
    {
        linkNode<T> *curNode = head->next;
        while (curNode)
        {
            printf("%d ", curNode->val);
            curNode = curNode->next;
        }
        printf("\n");
    }

    linkNode<T> *getHead()
    {
        return head;
    }

    void merge(sortList<T> list2)
    {
        linkNode<T> *newNode = list2.getHead()->next;
        while (newNode)
        {
            this->push(newNode->val);
            newNode = newNode->next;
        }
    }

private:
    int size;
    linkNode<T> *head;
};

int main()
{
    sortList<int> list1;
    list1.push(7);
    list1.push(6);
    list1.push(3);
    list1.push(4);
    list1.push(2);

    printf("print list1:\n");
    list1.printList();

    printf("pop 3 from the list:\n");
    list1.popElem(3);
    list1.printList();

    printf("pop 11 from the list:\n");
    list1.popElem(11);

    printf("\n");
    sortList<int> list2;
    list2.push(5);
    list2.push(8);
    list2.push(3);
    list2.push(1);

    printf("print list2:\n");
    list2.printList();

    printf("\n");

    printf("make list1 merge with list2:\n");
    list1.merge(list2);
    printf("print list1:\n");
    list1.printList();

    system("pause");
    return 0;
}