/*
    Topic: Achieve Doubly linked list
    Author:Sliverchen
    Create file date:   2021/4/21 21:13
*/

template <class T>
class DoubleListNode
{
public:
    DoubleListNode();
    ~DoubleListNode();

private:
    T val;
    DoubleListNode *next;
    DoubleListNode *pre;
    friend class DoublyList;
};

template <class T>
class DoublyList
{
};
