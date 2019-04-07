#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm> 
#include<stack>
#include<vector>
#include<queue>  
using namespace std;
const int maxn = 7;
struct node {
	int data;
	int lay;
	node *LChild, *RChild;
	node(int a=0,int c=1,node* l=NULL,node* r=NULL):data(a),lay(c),LChild(l),RChild(r){}
};
node* root = NULL;
int PreList[maxn],InList[maxn];
vector<int> LayList;
void Insert(node* &root, int a) {
	if (root == NULL) {
		root = new node(a);
		return;
	}
	if(root->LChild==root->RChild) Insert(root->LChild, a);
	else Insert(root->RChild, a);
}
node* Create(int a[],int n) {
	node* r = NULL;//指针一定要初始化
	for (int i = 0;i < n;i++)
		Insert(r, a[i]);
	return r;
}
void PreOrder(node* root) {//递归
	if (root == NULL) return;
	cout << root->data << " ";
	PreOrder(root->LChild);
	PreOrder(root->RChild);
}
void preOrder(node* root) {//非递归
	stack<node*> s;
	node* p;
	s.push(root);
	while (!s.empty()) {
		p = s.top();
		s.pop();
		cout << p->data << " ";
		if (p->RChild) s.push(p->RChild);
		if (p->LChild) s.push(p->LChild);
	}
}
void InOrder(node* root) {//递归
	if (root == NULL) return;
	InOrder(root->LChild);
	cout << root->data << " ";
	InOrder(root->RChild);
}
void inOrder(node* root) {//非递归
	stack<node*> s;
	node* p = root;
	while (p||!s.empty()) {
		while (p) {
			s.push(p);
			p = p->LChild;
		}
		p = s.top();
		s.pop();
		cout << p->data << " ";
		p = p->RChild;
	}
}
void PostOrder(node* root) {//递归
	if (root == NULL) return;
	PostOrder(root->LChild);
	PostOrder(root->RChild);
	cout << root->data << " ";
}
void postOrder(node* root) {//非递归
	stack<node*> s;
	node *p = root, *visit = NULL;
	while (p || !s.empty()) {
		if (p) {//找到最左结点
			s.push(p);
			p = p->LChild;
		}
		else {
			p = s.top();//左结点的父结点
			s.pop();
			if (p->RChild&&p->RChild != visit) {//右节点存在且未访问过
				s.push(p);
				p = p->RChild;
			}
			else {//左右结点都访问完了
				cout << p->data << " ";
				visit = p;
				p = NULL;
			}
		}
	}
}
void LayerOrder(node* root) {
	if (root == NULL) {
		cout << "空树" << endl;return;
	}
	queue<node*> q;
	int lay = 1;
	q.push(root);
	node* p;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (lay != p->lay) {
			lay++;cout << endl;
		}
		cout << p->data << " ";
		if (p->LChild) {
			p->LChild->lay = p->lay + 1;
			q.push(p->LChild);
		}
		if (p->RChild) {
			p->RChild->lay = p->lay + 1;
			q.push(p->RChild);
		}
	}
}
node* Pre_In(int pl, int pr, int il, int ir) {
	if (pl > pr) return NULL;
	int k = il;
	while (InList[k] != PreList[pl]) k++;
	node* root = new node(InList[k]);
	root->LChild = Pre_In(pl + 1, pl + k - il, il, k - 1);
	root->RChild = Pre_In(pl + k - il + 1, pr, k + 1, ir);
	return root;
}
node* Lay_In(vector<int> lay, int il, int ir) {
	if (lay.empty()) return NULL;
	node* root = new node(lay[0]);
	int k = il;
	while (InList[k] != lay[0]) k++;
	vector<int> layL, layR;
	for (size_t i = 1;i < lay.size();i++) {
		bool inLeft = false;
		for (int j = il;j < k;j++) {
			if (lay[i] == InList[j]) {
				inLeft = true;
				layL.push_back(lay[i]);break;
			}
		}
		if (!inLeft) layR.push_back(lay[i]);
	}
	root->LChild = Lay_In(layL, il, k - 1);
	root->RChild = Lay_In(layR, k + 1, ir);
	return root;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C:/Users/Administrator.WIN-20160308UMZ/Desktop/PG/PAT/input.txt", "r", stdin);
#endif    
	//int a[maxn];
	for (int i = 0;i < maxn;i++)
		LayList.push_back(i + 1);
	for (int i = 0;i < maxn;i++)
		cin >> InList[i];
	//root=Create(a, maxn);
	root = Lay_In(LayList, 0, maxn - 1);
	cout << "先序非递归:";
	preOrder(root);
	cout << endl << "先序递归:";
	PreOrder(root);
	cout << endl << "中序非递归:";
	inOrder(root);
	cout << endl << "中序递归:";
	InOrder(root);
	cout << endl << "后序非递归:";
	postOrder(root);
	cout << endl << "后序:";
	PostOrder(root);
	cout << endl << "层次:" << endl;
	LayerOrder(root);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048