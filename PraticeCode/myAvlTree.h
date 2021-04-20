/*
    Topic: achieve avl tree
    Author: Sliverchen
    Create File Date: 2021/4/19
    Explanation:
        imitate the code that i have written before(it is Mr.Wang's structure, which i should learn to)
*/
template <class T>
class AvlTree
{
    //平衡树节点结构
    struct AvlNode
    {
        T val;
        int height;
        AvlNode *left;
        AvlNode *right;
        AvlNode(const T &ele)
            : val(ele), left(nullptr), right(nullptr), height(0) {}
    };

public:
    typedef AvlNode node_t;

public:
    AvlTree() : root(nullptr) {}
    ~AvlTree()
    {
        clear();
        root = nullptr;
    }

    void Insert(const T &elem); //插入

    void Remove(const T &elem); //移除

    bool Contains(const T &elem) const; //查找

    void clear(); //清空

    void Traversal(const int &choose); //遍历(1->中序遍历；2->前序遍历)

private:
    static const int ALLOW_IMBALANCE = 1;

    node_t *root; //根节点

    void clear(node_t *&t); //清空

    void Insert(const T &elem, node_t *&t); //插入

    void Remove(const T &elem, node_t *&t); //删除

    bool contains(const T &elem, node_t *&t) const; //查找

    void In_order_traversal(node_t *&t); //中序遍历

    void Pre_order_traversal(node_t *&t); //前序遍历

    int GetHeight(node_t *&t); //获取节点高度

    void balance(node_t *&t); //平衡

    void rotateWithLeftChild(node_t *&k2); //左节点单旋转

    void rotateWithRightChild(node_t *&k2); //右节点单旋转

    void doubleWithLeftChild(node_t *&k3); //左节点双旋转

    void doubleWithRightChild(node_t *&k3); //右节点双旋转

    node_t *&FindMin(node_t *&t) //获取最小节点
    {
        if (t->left == nullptr)
            return t;
        return FindMin(t->left);
    }
};