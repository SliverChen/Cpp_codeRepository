#define DEFAULT_DATASIZE 10

template <class T>
class MyHashTable
{
public:
    MyHashTable();
    MyHashTable(const int &size);
    ~MyHashTable();
    void Insert(const T &elem);
    void Remove(const T &elem);
    bool Contains(const T &elem);
    void traversal();

private:
    int Hash(const T &elem);
    void clear();
    static const double load_factor = 0.75; //装填因子---->数据长度 / 表长 ---->表长 = 数据长度 * 装填因子
    vector<T> elements;
    int capacity;
};

template <class T>
MyHashTable<T>::MyHashTable()
{
    capacity = DEFAULT_DATASIZE * load_factor;
    elements.resize(capacity);
}

template <class T>
MyHashTable<T>::MyHashTable(const int &size)
{
    capacity = size * load_factor;
    elements.resize(capacity);
}

template <class T>
MyHashTable<T>::~MyHashTable()
{
}

template <class T>
void MyHashTable<T>::Insert(const T &elem)
{
}

template <class T>
void MyHashTable<T>::Remove(const T &elem)
{
}

template <class T>
bool MyHashTable<T>::Contains(const T &elem)
{
}

template <class T>
void MyHashTable<T>::traversal()
{
    for (auto elem : elements)
    {
        printf("%d ", elem);
    }
    printf("\n");
}

template <class T>
void MyHashTable<T>::clear()
{
}

template <class T>
int MyHashTable<T>::Hash(const T &elem)
{
    int p = capacity;
    return elem % p; //linear Hash
}