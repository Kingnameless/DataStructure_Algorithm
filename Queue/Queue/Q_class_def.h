#include <iostream>
using namespace std;

//环队
template <class T>
class Queue
{
	T* data;
	int front, rear;
	int Q_size;
public:
	Queue() { front = 0;rear = -1;data = nullptr;Q_size = 0; }
	Queue(int mysize) { front = 0;rear = -1;data = new T[mysize];Q_size = mysize; }
	bool Empty() const;
	bool Full() const;
	bool EnQueue(T q);
	bool DeQueue();
	int Length() const { return rear - front + 1; }
	bool Dispaly() const;
};
//链队
template <class T>
struct QNode
{
	T data;
	QNode<T>* next;
	QNode():next(NULL){}
	QNode(T x,QNode<T>* q=NULL):data(x),next(q){}
};
template <class T>
class Q_link
{
	QNode<T>* front;
	QNode<T>* rear;
	const int Q_size;
	//禁止复制与赋值的使用
	Q_link(const Q_link & q):Q_size(0){}
	Q_link & operator=(const Q_link & q) { return *this; }
public:
	Q_link(int mysize = size);
	bool Empty() const;
	bool Full() const;
	int Length() const;
	bool EnQueue(const T& q);
	bool DeQueue(T & q);
	bool dispaly() const;
	~Q_link();
};

//环队
template <class T>
bool Queue<T>::EnQueue(T q)
{
	if (Full())
	{
		cout << "Queue full!" << endl;
		return false;
	}
	data[++rear%Q_size] = q;
	return true;
}
template <class T>
bool Queue<T>::DeQueue()
{
	if (Empty())
	{
		cout << "Queue empty!" << endl;
		return false;
	}
	front++;
	return true;
}
template <class T>
bool Queue<T>::Empty() const
{
	return rear < front;
}
template <class T>
bool Queue<T>::Full() const
{
	return Length() == Q_size;
}
template <class T>
bool Queue<T>::Dispaly() const
{
	if (Empty())
	{
		cout << "Queue empty!" << endl;
		return false;
	}
	for (int i = front;i - front < Elem_num();i++)
		cout << i << ": " << data[i%Q_size] << endl;
	return true;
}
//链队
template <class T>
Q_link<T>::Q_link(int mysize) :Q_size(mysize)
{
	front = rear = nullptr;
}
template <class T>
int Q_link<T>::Length() const
{
	QNode<T>* p = front;int count = 0;
	while (p)
	{
		count++;p = p->next;
	}
	return count;
}
template <class T>
bool Q_link<T>::Empty() const
{
	return Length() == 0;
}
template <class T>
bool Q_link<T>::Full() const
{
	return Length() == Q_size;
}
template <class T>
bool Q_link<T>::EnQueue(const T & q)
{
	if (Full())
	{
		cout << "Queue full!" << endl;
		return false;
	}
	QNode<T>* x = new QNode<T>(q);
	if (Empty())
		front = x;
	else
		rear->next = x;
	rear = x;
	return true;
}
template <class T>
bool Q_link<T>::DeQueue(T & c)
{
	if (Empty())
	{
		cout << "Queue empty!" << endl;
		return false;
	}
	c = front->data;
	QNode<T>* x = front;
	front = front->next;
	delete x;
	if (Empty())
		rear = front;
	return true;
}
template <class T>
bool Q_link<T>::dispaly() const
{
	if (Empty())
	{
		cout << "Queue empty!" << endl;
		return false;
	}
	QNode<T>* x = front;
	while (x)
	{
		cout << x->data << endl;
		x = x->next;
	}
	return true;
}
template <class T>
Q_link<T>::~Q_link()
{
	QNode<T>* x;
	while (front)
	{
		x = front;
		front = front->next;
		delete x;
	}
	rear = nullptr;
}

