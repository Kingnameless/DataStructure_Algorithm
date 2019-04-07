using namespace std;
//LinkNode
template<class T>
struct LinkNode
{
	T data;
	LinkNode<T>* next;
	LinkNode(LinkNode<T>* p = NULL) { next = p; }
	LinkNode(const T & item, LinkNode<T>* p=NULL) { data = item;next = p; }
};
//Link类(带头结点）
template<class T>
class Link
{
	
	LinkNode<T>* head;
public:
	Link() { head = new LinkNode<T>; }//设置头结点
	Link(const T & x) { head = new LinkNode<T>(x); }
	~Link() { clear(); }
	void clear()const;//清空链表
	bool Empty() const { return head->next == NULL; }
	bool Full() const {return false;}//链表可任意长度
	int Length() const;//返回长度
	LinkNode<T>* Locate(int i)const;//定位
	int Search(T& x)const;//查找
	T* getdata(int i)const;//获取第i个元素数据
	bool setdata(int i, T& x)const;//修改第i个元素数据
	bool Insert(T& x, int i=0)const;//在第i个结点后插入，i=0在头结点后插入
	bool Delete(int i)const;//删除第i个节点
	bool Sort() const;//从大到小排序
	bool disp() const;
};

//Link类方法
template<class T>
void Link<T>::clear()const//清空
{
	LinkNode<T>* p;
	while (head->next)
	{
		p = head->next;
		head->next = p->next;
		delete p;
	}
}
template<class T>
int Link<T>::Length()const//返回链表长度
{
	int count = 0;
	LinkNode<T>* p = head;
	while (p->next)
	{
		p = p->next;
		count++;
	}
	return count;
}
template<class T>
LinkNode<T>* Link<T>::Locate(int i)const//定位第i个结点位置
{
	if (i < 0) return NULL;//i=0,定位头结点
	LinkNode<T>* p = head;
	while (p&&i > 0)
	{
		p = p->next;i--;
	}
	return p;
}
template<class T>
int Link<T>::Search(T& x)const//查找x在链表中的序号，链表为空，返回0
{
	LinkNode<T>* p = head->next;int i = 0;
	while (p)
	{
		i++;
		if (p->data == x) break;
		else
		{
			p = p->next;
		}
	}
	if (!p)return 0;//查找数据不存在
	return i;
}
template<class T>
T* Link<T>::getdata(int i)const//获取第i个结点的数据
{
	if (i < 1) return NULL;
	LinkNode<T>* p = Locate(i);
	if (p == NULL) return NULL;
	else return &p->data;
}
template<class T>
bool Link<T>::setdata(int i, T& x)const//设置第i个结点的数据
{
	if (i < 1) return false;
	LinkNode<T>* p = Locate(i);
	if (p == NULL) return false;
	else p->data = x;
	return true;
}
template<class T>
bool Link<T>::Insert(T& x, int i)const
{
	LinkNode<T>* p = Locate(i);
	if (p == NULL)return false;
	LinkNode<T>* q = new LinkNode<T>(x);
	q->next = p->next;p->next = q;
	return true;
}
template<class T>
bool Link<T>::Delete(int i)const
{
	LinkNode<T>* p = Locate(i - 1);
	if (p == NULL || p->next == NULL)return false;
	LinkNode<T>* q;
	q = p->next;p->next = q->next;//x = q->data;是否返回删除元素的值
	delete q;
	return true;
}
template<class T>
bool Link<T>::disp() const//遍历
{
	if (Empty())
	{
		cout << "Empty!" << endl;
		return false;
	}
	LinkNode<T>* p = head->next;
	while (p)
	{
		cout << p->data << endl;
		p = p->next;
	}
	return true;
}
template<class T>
//排序(从大到小)
bool Link<T>::Sort() const
{
	if (Empty())
		return false;
	T temp;
	for (int i = Length();i > 0;i--)
	{
		LinkNode<T>* p = head->next;
		for (int j = i - 1;j>0;j--)
		{
			if (p->next->data > p->data)
			{
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
	}
	return true;
}

	 

