#include <iostream>
#include <queue>
#include "BiTree_class.h"
using namespace std;

//将数组调整为最小堆
template <class E>
void siftDown(int begin, int end,E *a)
{
	int i = begin, j = 2 * i + 1;
	E temp = a[i];
	while (j <= end)
	{
		if (j < end) j = a[j] < a[j + 1] ? j : j + 1;
		if (temp > a[j])
		{
			a[i] = a[j];i = j;a[i] = temp;j = 2 * i + 1;
		}
		else
			break;
	}
}
template <class E>
void MinHeap(E *a,int n)
{
	int currentPos = (n - 2) / 2;
	while (currentPos >= 0)
	{
		siftDown(currentPos, n - 1, a);
		currentPos--;
	}
}
//堆排序(从大到小排序）
template <class E>
void HeapSort(E *a, int n)
{
	E temp;
	while (n > 0)
	{
		MinHeap(a, n);
		temp = a[0];a[0] = a[n - 1];a[n - 1] = temp;
		n--;
	}
}
//哈弗曼树(未完成）
template <class T>
struct huffmanNode
{
	huffmanNode<T> *LChild, *RChild, *parent;
	T val;
	huffmanNode(huffmanNode<T> *LC=NULL, huffmanNode<T> *RC=NULL,
		huffmanNode<T> *par=NULL,T v=0):LChild(LC),RChild(RC),parent(par),val(v){}
};
template <class T>
struct cmp {
	bool operator()(huffmanNode<T> &x, huffmanNode<T> &y)
	{
		return x.val > y.val;
	}
};
template <class T>
void huffmanTree(T H[],int n)
{
	priority_queue<huffmanNode<T>, vector<huffmanNode<T>>,cmp<huffmanNode<T>>> MinHp;
	for (int i = 0;i < n;i++)
	{
		huffmanNode<T> * h = new huffmanNode<T>(H[i]);
		MinHp.push(h);
	}
	while (!MinHp.empty())
	{
		huffmanNode<T> a = MinHp.top();MinHp.pop();
		huffmanNode<T> b = MinHp.top();MinHp.pop();
		huffmanNode<T> *c;mergeTree(a, b, c);
		if (!MinHp.empty())  MinHp.push(*c);
	}
}
template <class T>
huffmanNode<T> & mergeTree(huffmanNode<T> &x, huffmanNode<T> &y, huffmanNode<T> *z)
{

}
int main()
{
	int a[] = { 53,17,78,9,45,65,87,23 };
	HeapSort(a, 8);
	for (int i = 0;i < 8;i++)
	{
		cout << a[i] << " ";
		cout << endl;
	}
	
}