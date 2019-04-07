//顺序栈
#include <iostream>
using namespace std;

template <class T>
class stack
{
	int top;
	T* data;
	const int stack_size;//栈的容量
public:
	stack(int mySize=10);//初始化栈
	void ClearStack();
	bool StackEmpty() const;
	bool StackFull() const;
	bool GetTop(T& t) const;
	int GetSize() const;
	bool Push(T e);
	bool Pop(T& e);
	bool StackTraverse(); 
	~stack() { delete[] data; }
};
template <class T>
stack<T>::stack(int mySize):stack_size(mySize)
{
	data = new T[mySize];
	top = -1;
}
template <class T>
bool stack<T>::Push(T e)
{
	if (StackFull())
		return false;
	data[++top] = e;
	return true;
}
template <class T>
bool stack<T>::Pop(T& e)
{
	if (StackEmpty())
		return false;
	e = data[top--];
	return true;
}
template <class T>
//自上而下遍历
bool stack<T>::StackTraverse()
{
	if (StackEmpty())
	{
		cout << "Empty" << endl;
		return false;
	}
	int i = top;
	while (i != -1)
	{
		cout << data[i] << endl;
		i--;
	}
	return true;
}
template <class T>
bool stack<T>::StackEmpty() const
{
	return top == -1;
}
template <class T>
bool stack<T>::StackFull() const
{
	return top == stack_size - 1;
}
template <class T>
bool stack<T>::GetTop(T& t) const
{
	if (StackEmpty())
		return false;
	t = data[top];
	return true;
}
template <class T>
int stack<T>::GetSize() const
{
	return top + 1;
}
template <class T>
void stack<T>::ClearStack()
{
	top = -1;
}
