#include <iostream>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
template <class T>
struct BiTreeNode
{
	T data;
	BiTreeNode<T> *LChild, *RChild;
	BiTreeNode() { LChild = RChild = NULL; }
	BiTreeNode(T x, BiTreeNode<T>* l = NULL, BiTreeNode<T>* r = NULL) :LChild(l), RChild(r),data(x){}
};
template <class T>
class BiTree
{
	BiTreeNode<T>* root;
	T RefVal;
	BiTreeNode<T>* Create(BiTreeNode<T>* r) const;
	bool PreOrder(BiTreeNode<T>* r) const;
	int Height(BiTreeNode<T>* r) const;
	BiTreeNode<T>* PI_Create(T *PO, T *IO, int n);
public:
	BiTree() { root = NULL; }
	BiTree(T k):RefVal(k),root(NULL){}
	~BiTree() { Destroy(root); }
	void Destroy(BiTreeNode<T>* r);
	void Create() { root = Create(root);cout << endl; }
	void P_I_Create(T *PO, T *IO, int n) { root = PI_Create(PO,IO,n); }
	void PreOrder() const;
	void InOrder() const;
	void PostOrder() const;
	int Height()const { return Height(root); }
	void LevelOrder() const;
	void Display(T** a);
};

template <class T>
BiTreeNode<T>* BiTree<T>::Create(BiTreeNode<T>* r)const //前序遍历建立二叉树
{
	T x;
	cin >> x;
	if (x == RefVal)  return NULL  ;
	else
	{
		r = new BiTreeNode<T>(x);
		r->LChild=Create(r->LChild);
		r->RChild=Create(r->RChild);
	}
	return r;
}

/*template <class T>
bool BiTree<T>::PreOrder(BiTreeNode<T>* r) const
{
	if (r != NULL)
	{
		cout << r->data << " ";
		PreOrder(r->LChild);
		PreOrder(r->RChild);
		return true;
	}
	return false;
}*/
template <class T>
bool BiTree<T>::PreOrder(BiTreeNode<T>* r) const//先序非递归
{
	if (r == NULL) return false;
	cout << "这是非递归：" << endl;
	stack<BiTreeNode<T>*> s;
	BiTreeNode<T>* p = r;
	s.push(p);
	while (!s.empty())
	{
		p = s.top();s.pop();
		if (p != NULL)
		{
			cout << p->data << " ";
			s.push(p->RChild);
			s.push(p->LChild);
		}
	}
	return true;
}
template <class T>
void BiTree<T>::PreOrder() const
{
	if (!PreOrder(root))
		cout << "空树";
	cout << endl;
}
template <class T>
int BiTree<T>::Height(BiTreeNode<T>* r) const
{
	if (r != NULL)
		return Height(r->LChild) > Height(r->RChild) ? 
		Height(r->LChild) + 1 : Height(r->RChild) + 1;
	return 0;
}

template <class T>
void BiTree<T>::LevelOrder() const
{
	if (root == NULL)
		cout << "空树";
	else
	{
		BiTreeNode<T>* p;
		queue<BiTreeNode<T>*> Q;
		Q.push(root);
			while (!Q.empty())
			{
				p = Q.front();
				cout << p->data << " ";
				Q.pop();
				if (p->LChild) Q.push(p->LChild);
				if (p->RChild) Q.push(p->RChild);	
			}
	}
	cout << endl;
}
template <class T>
void BiTree<T>::Destroy(BiTreeNode<T>* r)
{
	if (r != NULL)
	{
		Destroy(r->LChild);
		Destroy(r->RChild);
		delete r;
	}
}
template <class T>
void BiTree<T>::Display(T** a)
{

	if (root == NULL)
		cout << "空树";
	else
	{
		BiTreeNode<T>* p;
		queue<BiTreeNode<T>*> Q;
		Q.push(root);
		while (!Q.empty())
		{
			p = Q.front();
			cout << p->data << " ";
			Q.pop();
			if (p->LChild) Q.push(p->LChild);
			if (p->RChild) Q.push(p->RChild);
		}
	}
}
template <class T>
void BiTree<T>::InOrder() const
{
	if (root == NULL)
	{
		cout << "空树！" << endl;
		return;
	}
	stack<BiTreeNode<T>*> s;
	BiTreeNode<T>* p = root;
	do
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->LChild;
		}
		if (!s.empty())
		{
			p = s.top();cout << p->data << " ";s.pop();
			p = p->RChild;
		}
	} while (!s.empty() || p != NULL);
}
template <class T>
void BiTree<T>::PostOrder() const
{
	if (root == NULL)
	{
		cout << "空树！" << endl;
		return;
	}
	stack<BiTreeNode<T>*> s;
	BiTreeNode<T>* p;
	s.push(root), s.push(root);
	while (!s.empty())
	{
		p = s.top();s.pop();
		if (!s.empty() && p == s.top())
		{
			if (p->RChild) s.push(p->RChild), s.push(p->RChild);
			if (p->LChild) s.push(p->LChild), s.push(p->LChild);
		}
		else
			cout << p->data << " ";
	}
}
template <class T>//由前序和中序遍历序列构造二叉树
BiTreeNode<T>* BiTree<T>::PI_Create(T *PO, T *IO, int n) 
{
	if (n == 0)
		return NULL;
	int k = 0;
	while ((*PO) != *(IO + k)) k++;
	BiTreeNode<T>* r = new BiTreeNode<T>(*PO);
	r->LChild = PI_Create(PO + 1, IO, k);
	r->RChild = PI_Create(PO + k + 1, IO + k + 1, n - k - 1);
	return r;
}




