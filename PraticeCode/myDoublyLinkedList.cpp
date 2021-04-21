/*
    Topic: Achieve Doubly linked list
    Author:Sliverchen
    Create file date:   2021/4/21 21:13
*/

template <class T>
class DoublyList;

template <class T>
class DoubleListNode
{
public:
    DoubleListNode(const T &elem);
    ~DoubleListNode();

private:
    T val;
    DoubleListNode *next;
    DoubleListNode *pre;
    void clear(DoubleListNode *&t);
    friend DoublyList<T>;
};

template <class T>
class DoublyList
{
public:
    typedef DoubleListNode<T> node_t;

public:
    DoublyList();
    ~DoublyList();
    void Insert(const T &elem);
    void Remove(const T &elem);
    void InsertHead(const T &elem);
    bool Contains(const T &elem);

private:
    DoubleListNode *head;
};

/***********************DoubleListNode member achieve***************************/

template <class T>
DoubleListNode<T>::DoubleListNode(const T &elem)
{
    val = elem;
    next = nullptr;
    pre = nullptr;
}

template <class T>
DoubleListNode<T>::~DoubleListNode()
{
    delete this;
}

template <class T>
void DoubleListNode<T>::clear(DoubleListNode *&t)
{
    if (t == nullptr)
        return;
    clear(t->next);
    delete t;
}

/**********************DoublyList member achieve**************************/

template <class T>
DoublyList<T>::DoublyList()
{
    head = nullptr;
}

template <class T>
DoublyList<T>::~DoublyList()
{
    head.clear(head);
}

template <class T>
void DoublyList<T>::Insert(const T &elem)
{
    if (head == nullptr)
        head->val = elem;
    else
    {
        node_t *curNode = head;
        while (curNode->next)
        {
            curNode = curNode->next;
        }
        node_t *newNode = new node_t(elem);
        curNode->next = newNode;
        newNode->pre = curNode;
    }
}

template <class T>
void DoublyList<T>::InsertHead(const T &elem)
{
    if (head == nullptr)
        head->val = elem;
    else
    {
        node_t *newNode = new node_t(elem);
        newNode->next = head;
        head->pre = newNode;
        head = newNode;
    }
}

template <class T>
void DoublyList<T>::Remove(const T &elem)
{
    if (head == nullptr)
        return;
    if (head->val == elem)
    {
        node_t *nextnode = head->next;
        head = nextnode;
        head->pre = nullptr;
    }
    else
    {
        node_t *curNode = head;
        node_t *preNode = nullptr;
        while (curNode->next)
        {
            if (curNode->val == elem)
            {
                node_t *oldNode = curNode;
                preNode->next = oldNode->next;
                oldNode->next->pre = preNode;
                delete oldNode;
                break;
            }
            preNode = curNode;
            curNode = curNode->next;
        }
    }
}

template <class T>
bool DoublyList<T>::Contains(const T &elem)
{
    if (head == nullptr)
        return false;
    if (head->val == elem)
        return true;
    else
    {
        node_t *curNode = head;
        while (curNode->next)
        {
            if (curNode->val == elem)
                return true;
            curNode = curNode->next;
        }
        return false;
    }
}