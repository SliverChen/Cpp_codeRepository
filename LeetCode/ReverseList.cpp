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
	myList()
	{
		head->next = NULL;
		size = 0;
	}

	int getSize()
	{
		return size;
	}

	LinkNode<T> *getHead()
	{
		return head;
	}

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

private:
	LinkNode<T> *head;
	int size;
};

int main()
{
	myList<int> mylist;
	mylist.push_back(1);
	mylist.push_back(3);
	mylist.push_back(5);
	mylist.push_back(6);
	mylist.push_back(7);
	mylist.push_back(8);
	mylist.printList();
	system("pause");
	return 0;
}
