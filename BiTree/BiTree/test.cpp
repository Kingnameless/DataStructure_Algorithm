#include <iostream>
#include "BiTree_class.h"
#include <vector>
using namespace std;
struct Node {
	int *pos;
	int left;
	int right;
};
void PI(int *PO, int *IO, int n)
{
	if (n == 0)
		;
	else
	{
		queue<Node> Q;
		Node p, s, t;
		p.pos = PO + n - 1;
		p.left = 0;p.right = n - 1;
		Q.push(p);
		while (!Q.empty())
		{
			p = Q.front();
			cout << *p.pos << "*";
			Q.pop();
			int k = 0;
			while (*p.pos != *(IO + k)) k++;
			if (k > p.left)
			{
				s.left = p.left;s.right = k - 1;s.pos = p.pos - p.right + k - 1;
				Q.push(s);
			}
			if (k < p.right)
			{
				t.left = k + 1;t.right = p.right;t.pos = p.pos - 1;Q.push(t);
			}
		}
	}
}



int main()
{
	int po[] = { 2,3,1,5,7,6,4 };
	int io[] = { 1,2,3,4,5,6,7 };
	PI(po, io, 7);
	return 0;
}