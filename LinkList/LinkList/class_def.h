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
//Link��(��ͷ��㣩
template<class T>
class Link
{
	
	LinkNode<T>* head;
public:
	Link() { head = new LinkNode<T>; }//����ͷ���
	Link(const T & x) { head = new LinkNode<T>(x); }
	~Link() { clear(); }
	void clear()const;//�������
	bool Empty() const { return head->next == NULL; }
	bool Full() const {return false;}//��������ⳤ��
	int Length() const;//���س���
	LinkNode<T>* Locate(int i)const;//��λ
	int Search(T& x)const;//����
	T* getdata(int i)const;//��ȡ��i��Ԫ������
	bool setdata(int i, T& x)const;//�޸ĵ�i��Ԫ������
	bool Insert(T& x, int i=0)const;//�ڵ�i��������룬i=0��ͷ�������
	bool Delete(int i)const;//ɾ����i���ڵ�
	bool Sort() const;//�Ӵ�С����
	bool disp() const;
};

//Link�෽��
template<class T>
void Link<T>::clear()const//���
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
int Link<T>::Length()const//����������
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
LinkNode<T>* Link<T>::Locate(int i)const//��λ��i�����λ��
{
	if (i < 0) return NULL;//i=0,��λͷ���
	LinkNode<T>* p = head;
	while (p&&i > 0)
	{
		p = p->next;i--;
	}
	return p;
}
template<class T>
int Link<T>::Search(T& x)const//����x�������е���ţ�����Ϊ�գ�����0
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
	if (!p)return 0;//�������ݲ�����
	return i;
}
template<class T>
T* Link<T>::getdata(int i)const//��ȡ��i����������
{
	if (i < 1) return NULL;
	LinkNode<T>* p = Locate(i);
	if (p == NULL) return NULL;
	else return &p->data;
}
template<class T>
bool Link<T>::setdata(int i, T& x)const//���õ�i����������
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
	q = p->next;p->next = q->next;//x = q->data;�Ƿ񷵻�ɾ��Ԫ�ص�ֵ
	delete q;
	return true;
}
template<class T>
bool Link<T>::disp() const//����
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
//����(�Ӵ�С)
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

	 

