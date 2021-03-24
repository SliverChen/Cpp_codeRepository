/*
Author: SLiverChen
Date: 2021/3/21
Title:反转链表

Request:

the array is a linkedlist

In: [1,2,3,4,5] left:2 right: 4    1->2->3->4->5
Out:[1,4,3,2,5]                    1->4->3->2->5

In: [1] left:1 right:1
Out:[1]


解法1：时间复杂度O(n^2)
从left位置i开始，将第i个节点的值与第i+1个节点的值对换，直到i==right为止
随后将第i+1个节点的值与第i+2个节点的值对换，直到i+1==right-1为止
按照上面的遍历依次进行直到将第right-1个节点的值与第right个节点的值对换后，循环结束 

解法2：时间复杂度O(n)
设置三个临时指针 pre cur temp
首先将pre指向null，cur指向head(头指针)  temp指向cur.next
将cur.next = pre 即完成反转操作
之后pre = cur  cur = temp 再重复上面的两个操作 
*/

#include <iostream>
#include <list>
using namespace std;


//链表的节点结构
template <class T>
struct LinkNode
{
	T val;
	LinkNode *next;
	LinkNode(T va)
	{
		val = va;
		next = NULL;
	}
	LinkNode()
	{
		val = T();
		next = NULL;
	}
};

template <class T>
class myList
{
public:
	//构造函数(无参)
	myList()
	{
		head->next = NULL;
		size = 0;
	}

	//获取链表头节点
	LinkNode<T> *getHead()
	{
		return head;
	}

	//将元素插入到链表的最后的位置
	void push_back(T element)
	{
		LinkNode<T> *temp = head;
		LinkNode<T> *next = new LinkNode<T>(element);
		for (int i = 0; i < size; i++)
		{
			temp = temp->next;
		}
		temp->next = next;
		size++;
	}

	//删除链表的最后一个节点
	void pop_back()
	{
		LinkNode<T> *temp = head;
		for (int i = 0; i < size; i++)
		{
			temp = temp->next;
		}
		temp = NULL;
		size--;
	}

	//打印链表
	void printList()
	{
		LinkNode<T> *temp = head;
		for (int i = 0; i < size; i++)
		{
			temp = temp->next;
			cout << temp->val << " -> ";
		}
		cout << endl;
	}

	//在对应索引之前插入节点
	bool Insert(T element, int index)
	{
		LinkNode<T> *preNode = head;
		if (index <= 0 || index > size)
		{
			printf("index out of range,which index is %d, size is %d \n",index,size);
			return false;
		}
		for (int i = 0; i < index-1; i++)
		{
			preNode = preNode->next;
		}
		LinkNode<T> *newNode = new LinkNode<T>(element);
		newNode->next = preNode->next;
		preNode->next = newNode;
		size++;
		return true;
	}

	//删除索引对应的节点
	bool Remove(int index)
	{
		LinkNode<T> *preNode = head;
		if(index <=0 || index > size)
		{
			printf("index out of range, which index is %d, size is %d \n", index, size);
			return false;
		}
		for (int i = 0; i < index - 1;i++)
		{
			preNode = preNode->next;
		}
		LinkNode<T> *RemoveNode = preNode->next;
		preNode->next = RemoveNode->next;
		delete RemoveNode;
		size--;
		return true;
	}

	//清空链表操作
	bool Clear()
	{
		delete head->next;
		head->next = new LinkNode<T>();
		size = 0;
		return true;
	}

	//获取链表大小
	int GetListSize()
	{
		return size;
	}

	//反转整个链表的节点  例：1->2->3   ----->     3->2->1
	void ReverseWholeList()
	{

	}
	//反转链表的部分节点  例：1->2->3->4  left:2  right:3    ----->  1->3->2->4
	void ReversePartOfList(int leftIndex,int rightIndex)
	{

	}

private:
	LinkNode<T> *head;
	int size;
};

int main()
{


	system("pause");
	return 0;
}
