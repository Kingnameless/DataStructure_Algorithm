#include <iostream>
#include <math.h>
using namespace std;
#define max 100000
bool Prime_1(int n)//O(n)
{
	int top = (int)sqrt(1.0*n);
	if (n < 2) return false;
	for (int i = 2;i < top;i++)
		if (n%i == 0)
			return false;
	return true;
}
//埃氏筛法
bool IsPrime[max] = { 0 };
int Prime[max] = { 0 };
int Prime_2(int n)//O(n loglog n)
{
	int count = 0;
	for (int i = 2;i <= n;i++)
		if (!IsPrime[i])
		{
			Prime[count++] = i;
			for (int j = i*i;j <= n;j += i)
				IsPrime[j] = true;
		}
	return count;
}
//欧拉线性筛法
/*这里不是用i的倍数来消去合数，而是把 prime里面纪录的素数，
升序来当做要消去合数的最小素因子。
i在消去合数中的作用是当做倍数的。*/
int Prime_3(int n)
{
	int count = 0;
	for (int i = 2;i <= n;i++)
	{
		if (!IsPrime[i])
			Prime[count++] = i;
		for (int j = 0;i*Prime[j] <= n&&j < count;j++)
		{
			IsPrime[i*Prime[j]] = true;
			if (i%Prime[j] == 0) break;
		}
	}
	return count;
}
int main()
{
	int N;
	scanf("%d", &N);
	int num=Prime_3(N);
	for (int i = 0;i < num;i++)
	{
		if (i % 7 == 0)
			printf("\n");
		printf("%d ", Prime[i]);
	}
}