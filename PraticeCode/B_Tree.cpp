/********************************************************
 * Topic：B-Tree的函数实现
 * Author：Sliverchen
 * date : 2021 / 5 / 19
 * ******************************************************/

#include "./B_Tree.h"
#include <cstdio>
#include <cstdlib>

/*
    功能1实现：
    包含函数：
        SearchBTree,searchKey

*/

Status SearchBTree(BTree root, KeyType k, result &re)
{
    BTree cp = root;
    BTree before = NULL;

    //如果根节点为空，则返回error
    if (root == NULL)
    {
        re.tag = 0;
        re.pt = NULL;
        re.i = -1;
        return ERROR;
    }

    int resultKey = 1;
    while (cp != NULL)
    {
        resultKey = searchKey(cp, k);
        if (resultKey <= cp->keyNum && cp->key[resultKey] == k)
        {
            re.i = resultKey;
            re.pt = cp;
            re.tag = 1;
            return SUCCESS;
        }
        before = cp;
        cp = cp->ptr[resultKey - 1];
        //找不到会返回resultKey右边的位置，所以要回去resultKey以遍历它的子结点
    }
    re.tag = 0;
    re.pt = before;
    re.i = resultKey;
    return ERROR;
}

//返回指定关键字的位置，如果没有则返回比关键字小的最后一位
int searchKey(BTree node, KeyType k)
{
    if (node == NULL)
        return ERROR;
    int left = 1;
    int right = node->keyNum;

    while (left <= right)
    {
        int middle = left + ((right - left)) >> 1; //防止溢出，移位更高效
        if (node->key[middle] > k)
            right = middle - 1;
        else if (node->key[middle] < k)
            left = middle + 1;
        else
            return middle;
    }
    return left;
}

/*
    功能2实现：
    包含函数：
        InsertBTree(BTree &root,KeyType k)
        InsertNode(BTree &root,int KeySite,KeyType k,BTree &node)
        SplitToTwo(BTree &root,BTree &SplitRight)
        NewBroot(BTree &root,BTree left,BTree right,KeyType k)
    
    插入的流程：
        1、判断根是否存在，不存在则生成新根
        2、判断关键字是否存在，存在则返回ERROR
        3、找到要插入的层，由于关键字中多留了一个m位置，并且b树限定了单结点的关键字最大容量是m-1
            因此当位置m进行插入的时候，就要考虑分裂
        4、分裂后进行根的处理，首先把mid位置的key插入到根中，接着判断根是否需要进行分裂，需要则进行循环，直到不需要分裂为止
*/

Status InsertBTree(BTree &root, KeyType k)
{
    if (root == NULL)
    {
        if (NewBroot(root, NULL, NULL, k) == SUCCESS)
            return SUCCESS;
    }
    else
    {
        result re;
        if (SUCCESS == SearchBTree(root, k, re))
            return ERROR;
        BTree node = re.pt;
        int KeySite = re.i;
        BTree SplitRight = NULL;
        KeyType midKey;

        while (node != NULL)
        {
            if (InsertNode(node, KeySite, k, SplitRight) == ERROR)
                return ERROR;
            if (node->keyNum < m)
            {
                return SUCCESS;
            }
            else
            {
                midKey = node->key[(m + 1) >> 1];
                SplitRight = NULL;
                if (SplitToTwo(node, SplitRight) == ERROR)
                    return ERROR;
                else
                {
                    if (node->parent == NULL)
                    {
                        if (NewBroot(root, node, SplitRight, midKey) == SUCCESS)
                        {
                            return SUCCESS;
                        }
                    }
                    else
                    {
                        node = node->parent;
                        KeySite = searchKey(node, midKey);
                        k = midKey;
                    }
                }
            }
        }
    }
    return ERROR;
}

//插入结点，其中root是某一层，keySite是要插入的地方，k是要插入的关键字，node是keysite对应的ptr
//注意插入的地方只能是叶子节点，因此要从叶子节点的上一层进行插入，这样能让新插入的结点中的父亲结点指向当前结点
Status InsertNode(BTree &root, int KeySite, KeyType k, BTree &node)
{
    if (root == NULL)
        return ERROR;
    int keyNum = root->keyNum;
    for (int i = keyNum; i >= KeySite; i--)
    {
        root->key[i + 1] = root->key[i];
        root->ptr[i + 1] = root->ptr[i];
    }
    root->key[KeySite] = k;
    root->ptr[KeySite] = node;

    if (node != NULL)
        node->parent = root;
    root->keyNum++;
    return SUCCESS;
}

//将root中的关键字分割成两部分并存放到两个结点中，注意左半部分留在root，右半部分放在splitright中
Status SplitToTwo(BTree &root, BTree &SplitRight)
{
    int mid = (m + 1) >> 1;

    //初始化splitRight的结点
    SplitRight = (BTree)malloc(sizeof(BTNode));

    if (SplitRight == NULL) //如果堆空间内存分配失败
        return ERROR;

    SplitRight->parent = NULL;
    SplitRight->keyNum = 0;

    for (int i = 0; i <= m; ++i)
    {
        SplitRight->ptr[i] = NULL;
    }

    //将splitright的子结点指向root的右半部分的孩子结点

    //将ptr[0]单独划分是为了下面能从1开始
    //因为key[0]不存值，因此key的索引从1开始
    SplitRight->ptr[0] = root->ptr[mid];

    for (int i = mid + 1; i <= root->keyNum; i++)
    {
        SplitRight->key[i - mid] = root->key[i];
        SplitRight->ptr[i - mid] = root->ptr[i];
        SplitRight->keyNum++;
    }

    root->keyNum = mid - 1;

    //修改splitRight的父亲节点
    SplitRight->parent = root->parent;

    //修改splitRight子节点的父亲节点
    for (int i = 0; i <= SplitRight->keyNum; i++)
        if (SplitRight->ptr[i] != NULL)
            SplitRight->ptr[i]->parent = SplitRight;
    return SUCCESS;
}

//生成一个新结点，一般是生成根节点，否则left和right之前的父亲节点就会取代为新的结点，导致不知道原本哪个节点是它们的父亲节点
Status NewBroot(BTree &root, BTree left, BTree right, KeyType k)
{
    root = (BTree)malloc(sizeof(BTNode));

    if (root == NULL) //如果申请堆空间内存失败
        return ERROR;
    for (int i = 0; i <= m; ++i)
        root->ptr[i] = NULL;

    root->keyNum = 1;
    root->parent = NULL;
    root->ptr[0] = left;
    root->ptr[1] = right;
    root->key[1] = k;

    if (left != NULL)
        left->parent = root;
    if (right != NULL)
        right->parent = root;

    return SUCCESS;
}

/*
    功能3实现
    包含的函数:
        DeleteBTree(BTree &root,KeyType k)
        Restore(BTree &node)
        Merge(BTree &left,BTree &right,BTree &Parent)
        DeleteNode(BTree &node,int KeySite)
    删除的步骤：
        1、先查找是否存在该元素，如果不存在则直接返回error
        2、判断该元素所在节点是否含有左右孩子，如果有则上移孩子节点中的某相近元素（左孩子最右的节点或者右孩子最左的节点）
        3、如果没有左右孩子，则直接删除，然后移动
        4、删除元素，移动相应元素之后，如果某节点中元素数目小于ceil(m/2)-1，则需要看其某个相邻节点是否丰满
        5、如果丰满，则向父亲节点借一个元素来满足条件
        6、如果其相邻兄弟节点借了之后节点数目小于ceil(m/2)-1，则该节点与其相邻的某一结点进行合并形成一个节点，以此来满足条件
*/

Status DeleteBTree(BTree &root, KeyType k)
{
    if (root == NULL)
        return ERROR;

    result re;
    if (SearchBTree(root, k, re) == ERROR)
        return ERROR;
    BTree node = re.pt;
    int keySite = re.i;

    BTree nodeLeft = NULL;  //左孩子
    BTree nodeRight = NULL; //右孩子

    int keySiteLeft;
    KeyType keyLeft;  //左孩子的最右关键字
    KeyType keyRight; //右孩子的最左关键字

    if (node->ptr[keySite] != NULL)
    {
        nodeRight = node->ptr[keySite];

        while (nodeRight->ptr[0] != NULL)
        {
            nodeRight = nodeRight->ptr[0];
        }

        keyRight = nodeRight->key[1];
        node->key[keySite] = keyRight;

        DeleteNode(nodeRight, 1);

        if (nodeRight->keyNum < ((m + 1) >> 1 - 1))
            Restore(nodeRight);
    }

    else if (node->ptr[keySite - 1] != NULL)
    {
        nodeLeft = node->ptr[keySite - 1];

        keySiteLeft = nodeLeft->keyNum;

        while (nodeLeft->ptr[keySiteLeft] != NULL)
        {
            nodeLeft = nodeLeft->ptr[keySiteLeft];
            keySiteLeft = nodeLeft->keyNum;
        }

        keyLeft = nodeLeft->key[keySiteLeft];
        node->key[keySite] = keyLeft;
        DeleteNode(nodeLeft, keySiteLeft);

        if (nodeLeft->keyNum < ((m + 1) >> 1 - 1))
            Restore(nodeLeft);
    }
    else if (node->ptr[keySite - 1] == NULL && node->ptr[keySite] == NULL)
    {
        if (DeleteNode(node, keySite) == ERROR)
            return ERROR;
        if (node->keyNum < ((m + 1) >> 1 - 1))
            Restore(node);
    }
    if (root->keyNum == 0 && root->ptr[0] != NULL && root->ptr[0]->keyNum != 0)
    {
        BTree p = root;
        root = root->ptr[0];
        free(p);
        root->parent = NULL;
    }
    else if (root->keyNum == 0 && root->ptr[0] == NULL)
    {
        BTree p = root;
        free(p);
        root = NULL;
    }
    return SUCCESS;
}

Status Restore(BTree &node)
{
    BTree Parent = NULL;
    do
    {
        Parent = node->parent;
        if (node == NULL)
            return ERROR;
        if (Parent == NULL)
            return ERROR;

        int ptrSite = 0;
        for (int i = 0; i <= Parent->keyNum; ++i)
        {
            if (node == Parent->ptr[i])
            {
                ptrSite = i;
                break;
            }
        }

        int ptrSiteRight = ptrSite + 1;
        int ptrSiteLeft = ptrSite - 1;
        KeyType parentKey;

        int finished = 0; //用于判断是否完成在邻接节点富裕情况下的调整

        //如果node处在中间
        if (ptrSite >= 1 && ptrSite < Parent->keyNum)
        {
            //如果右子树满
            if (Parent->ptr[ptrSiteRight]->keyNum > (m + 1) >> 1 - 1)
            {
                parentKey = Parent->key[ptrSiteRight];
                Parent->key[ptrSiteRight] = Parent->ptr[ptrSiteRight]->key[1];

                InsertNode(node, node->keyNum + 1, parentKey, Parent->ptr[ptrSiteRight]->ptr[0]);
                DeleteBTree(Parent->ptr[ptrSiteRight], 0);
            }

            //如果左邻节点满，则取左邻的最右边的元素
            else if (Parent->ptr[ptrSiteLeft]->keyNum > (m + 1) >> 1 - 1)
            {
                int RightFinal = Parent->ptr[ptrSiteLeft]->keyNum;

                parentKey = Parent->key[ptrSite];
                Parent->key[ptrSite] = Parent->ptr[ptrSiteLeft]->key[RightFinal];

                InsertNode(node, 1, parentKey, node->ptr[0]);
                node->ptr[0] = Parent->ptr[ptrSiteLeft]->ptr[RightFinal];

                DeleteNode(Parent->ptr[ptrSiteLeft], RightFinal);

                finished = 1;
            }
        }
        //如果node处在最左边
        else if (ptrSite == 0)
        {
            //如果右子树丰满
            if (Parent->ptr[ptrSiteRight]->keyNum > (m + 1) >> 1 - 1)
            {
                parentKey = Parent->key[ptrSiteRight];
                Parent->key[ptrSiteRight] = Parent->ptr[ptrSiteRight]->key[1];

                InsertNode(node, node->keyNum + 1, parentKey, Parent->ptr[ptrSiteRight]->ptr[0]);
                DeleteNode(Parent->ptr[ptrSiteRight], 0);
                finished = 1;
            }
        }

        //如果node处在最右边
        else if (ptrSite == Parent->keyNum)
        {
            //如果左邻节点丰满，则取左邻的最右边的元素
            if (Parent->ptr[ptrSiteLeft]->keyNum > (m + 1) >> 1 - 1)
            {
                parentKey = Parent->key[ptrSite];

                int RightFinal = Parent->ptr[ptrSiteLeft]->keyNum;
                InsertNode(node, 1, parentKey, node->ptr[0]);
                node->ptr[0] = Parent->ptr[ptrSiteLeft]->ptr[RightFinal];

                DeleteNode(Parent->ptr[ptrSiteLeft], RightFinal);
                finished = 1;
            }
        }

        //如果此时相邻节点都不丰满
        if (finished == 0)
        {
            if (ptrSite >= 1 && ptrSite <= Parent->keyNum)
                Merge(Parent->ptr[ptrSiteLeft], node, Parent);
            else if (ptrSite == 0)
                Merge(node, Parent->ptr[1], Parent);
            else if (ptrSite == Parent->keyNum)
                Merge(Parent->ptr[Parent->keyNum - 1], node, Parent);
        }

        if (Parent->keyNum < ((m + 1) >> 1 - 1) && Parent->parent != NULL && Parent->parent->keyNum != 0)
        {
            node = Parent;
        }
    } while (Parent->keyNum < ((m + 1) >> 1 - 1) && Parent->parent != NULL && Parent->parent->keyNum != 0);
    return SUCCESS;
}

//合并两个节点，统一操作，右边合并到左边
Status Merge(BTree &Left, BTree &Right, BTree &Parent)
{
    int parentKeySite = 0;
    for (int i = 0; i <= Parent->keyNum; ++i)
    {
        if (Parent->ptr[i] == Left)
        {
            parentKeySite = i;
            break;
        }
    }

    parentKeySite += 1;
    KeyType parentKey = Parent->key[parentKeySite];

    //将parentKey插入到左边，并且将右邻的第一个孩子转移过来
    InsertNode(Left, Left->keyNum + 1, parentKey, Right->ptr[0]);

    //把右边的所有关键字插入到左边
    for (int i = 0; i <= Right->keyNum; ++i)
        InsertNode(Left, Left->keyNum + 1, Right->key[i], Right->ptr[i]);

    //释放掉不要的节点
    BTree freeNode = Parent->ptr[parentKeySite];
    Parent->ptr[parentKeySite] = NULL;

    DeleteNode(Parent, parentKeySite);

    free(freeNode);
    freeNode = NULL;

    return SUCCESS;
}

//在叶子层删除某个关键字
Status DeleteNode(BTree &node, int keySite)
{
    if (node == NULL)
        return ERROR;
    for (int i = keySite; i <= node->keyNum; ++i)
    {
        node->key[i] = node->key[i + 1];
        node->ptr[i] = node->ptr[i + 1];
    }
    node->keyNum--;
    return SUCCESS;
}

/*
    功能4实现
    包含的函数：
        Aoprint(BTree T,int depth)
        Destroy(BTree &T)
        Depth(BTree T)
        Leaves(BTree T)
        AscOrderTraverse(BTree T)
        DesOrderTraverse(BTree T)
*/

//凹入表打印b树
void Aoprint(BTree T, int depth)
{
    if (T == NULL)
        return;
    for (int i = T->keyNum; i > 0; --i)
    {
        Aoprint(T->ptr[i], depth + 1);
        for (int j = 0; j < depth; j++)
            printf("    ");
        printf("%d\n", T->key[i]);
    }
    Aoprint(T->ptr[0], depth + 1);
}

//销毁b树
void Destroy(BTree &T)
{
    if (T != NULL)
    {
        for (int i = 0; i <= T->keyNum; ++i)
            Destroy(T->ptr[i]);
        free(T);
        T = NULL;
    }
}

//求深度
int Depth(BTree &T)
{
    if (T == NULL)
        return 0;
    int depth, max = 0;
    for (int i = 0; i <= T->keyNum; ++i)
    {
        depth = Depth(T->ptr[i]);
        max = depth > max ? depth : max;
    }
    return max + 1;
}

//求叶子数
int Leaves(BTree &T)
{
    if (NULL == T)
        return 0;
    int leaves = 0, isleave = -1;
    for (int i = 0; i <= T->keyNum; ++i)
    {
        if (T->ptr[i] != NULL)
        {
            leaves += Leaves(T->ptr[i]);
            isleave = 0;
        }
    }
    if (isleave)
        return 1;
    return leaves;
}

//升序遍历
void AscOrderTraverse(BTree &T)
{
    if (NULL == T)
        return;
    AscOrderTraverse(T->ptr[0]);
    for (int i = 1; i <= T->keyNum; ++i)
    {
        printf("%d\t", T->key[i]);
        AscOrderTraverse(T->ptr[i]);
    }
}

//降序遍历
void DesOrderTraverse(BTree &T)
{
    if (NULL == T)
        return;
    for (int i = T->keyNum; i > 0; --i)
    {
        DesOrderTraverse(T->ptr[i]);
        printf("%d\t", T->key[i]);
    }
    DesOrderTraverse(T->ptr[0]);
}