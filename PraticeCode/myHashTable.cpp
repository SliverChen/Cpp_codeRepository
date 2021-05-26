#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
/*
    对装填因子的补充说明：
        这里为了方便设置了经过科学家研究得出的最佳装填因子0.75
        但是实际上因为关键字的数量一般是不确定的，因此我们无法第一时间将哈希表的长度确定下来
        所以一般都是先对哈希表设定一个初始长度，等到当装填因子 = 关键字个数 / 长度 >= 1的时候
        我们需要对哈希表进行扩容，并且重新对表中的所有元素哈希映射到新的哈希表上
        由于这里过于繁琐，理解大致思路即可
*/

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
    int Hash_minus(const T &elem);             //除留取余
    int Hash_Directly(const T &elem);          //直接法
    int Hash_getMidInSquare(const T &elem);    //平方取中
    int Hash_Fold(const T &elem);              //折叠法
    int ReHash_LinearSearch(const int &index); //线性探测
    int ReHash_SquareSearch(const int &index); //平方探测
    int ReHash_RandomSearch();                 //伪随机探测
    int ReHash_Hash(const T &elem);            //再散列
    void clear();                              //清空
    double load_factor = 0.75;                 //装填因子---->数据长度 / 表长 ---->表长 = 数据长度 * 装填因子
    vector<pair<T, bool>> elements;            //存储一对键值（关键字+是否已被存储过）
    vector<int> Public;                        //公共溢出区
    int capacity;
};

template <class T>
MyHashTable<T>::MyHashTable()
{
    capacity = DEFAULT_DATASIZE * load_factor;
    elements.resize(capacity);
    for (auto &p : elements)
    {
        p.first = -1;
        p.second = 0;
    }
}

template <class T>
MyHashTable<T>::MyHashTable(const int &size)
{
    capacity = size * load_factor;
    elements.resize(capacity);
    for (auto &p : elements)
    {
        p.first = -1;
        p.second = 0;
    }
}

template <class T>
MyHashTable<T>::~MyHashTable()
{
}

template <class T>
void MyHashTable<T>::Insert(const T &elem)
{
    int index = Hash_minus(elem);
    if (elements[index].second == 0)
    {
        elements[index].first = elem;
        elements[index].second = true;
        return;
    }

    int time = 0; //防止表中已满导致无法找到合适的位置进行插入从而进入死循环状态
    while (elements[index].second == 1 && time <= capacity + 5)
    {
        index = ReHash_LinearSearch(index);
        time++;
    }
    if (time == capacity + 6)
    {
        printf("can not find the suitable position to insert the elem %d \n", elem);
        return;
    }
    elements[index].first = elem;
    elements[index].second = 1;
}

template <class T>
void MyHashTable<T>::Remove(const T &elem)
{
    int index = Hash_minus(elem);
    while (elements[index].first != elem)
    {
        index = ReHash_LinearSearch(index);
    }
    elements[index].first = -1;
    elements[index].second = false;
}

template <class T>
bool MyHashTable<T>::Contains(const T &elem)
{
    int index = Hash_minus(elem);
    while (elements[index].first != elem && elements[index].second == 1)
        index = ReHash_LinearSearch(index);
    if (elements[index].second == 0)
        return false;
    return true;
}

template <class T>
void MyHashTable<T>::traversal()
{
    for (auto &value : elements)
        printf("%d ", value);
    printf("\n");
}

template <class T>
void MyHashTable<T>::clear()
{
    elements.clear();
}

template <class T>
int MyHashTable<T>::Hash_minus(const T &elem)
{
    return elem % capacity;
}

template <class T>
int MyHashTable<T>::Hash_Directly(const T &elem)
{
    return elem;
}

template <class T>
int MyHashTable<T>::Hash_getMidInSquare(const T &elem)
{
    T s = pow(elem, 2);
    string tmp = to_string(s);
    int n = tmp.size();
    return tmp[n >> 1] - '0';
}

template <class T>
int MyHashTable<T>::Hash_Fold(const T &elem)
{
    string tmp = to_string(elem);
    T res = 0;
    for (int i = 0; i < tmp.size() - 1; i += 2)
    {
        res += ((tmp[i] - '0') * 10 + (tmp[i + 1] - '0'));
    }
    return res % 10;
}

template <class T>
int MyHashTable<T>::ReHash_LinearSearch(const int &index)
{
    return (index + 1) % capacity;
}

template <class T>
int MyHashTable<T>::ReHash_SquareSearch(const int &index)
{
    return (int)(pow(index, 2)) % capacity;
}

template <class T>
int MyHashTable<T>::ReHash_RandomSearch()
{
    default_random_engine e(time(0));                      //时间引擎
    uniform_int_distribution<unsigned> u(0, capacity - 1); //生成[0,capacity-1]范围的某个int类型数据
    return u(e);
}

int main()
{
    MyHashTable<int> myhashTable;
    myhashTable.Insert(4);
    myhashTable.Insert(3);
    myhashTable.traversal();
    myhashTable.Insert(14);
    myhashTable.traversal();
    cout << myhashTable.Contains(3) << endl;
    cout << myhashTable.Contains(13) << endl;
    system("pause");
    return 0;
}