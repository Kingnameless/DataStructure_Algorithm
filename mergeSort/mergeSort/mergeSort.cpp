#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxsize = 100;
void merge(int a[], int L1, int R1,int L2,int R2) {
	int t[maxsize];int i = L1, j = L2, k = 0;
	while (i <= R1&&j <= R2) {
		if (a[i] <= a[j]) t[k++] = a[i++];
		else t[k++] = a[j++];
	}
	while (i <= R1) t[k++] = a[i++];
	while (j <= R2) t[k++] = a[j++];
	for (int s = 0;s < k;s++)
		a[L1 + s] = t[s];
}
void mergeSort1(int a[], int left,int right) {//归并排序递归
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort1(a, left, mid);mergeSort1(a, mid + 1, right);
		merge(a, left, mid, mid + 1, right);
	}
}
void mergeSort2(int a[],int n) {//归并排序非递归
	for (int step = 2;step/2 < n;step *=2) {
		for (int i = 0;i < n;i += step) {
			int mid = i + step / 2 - 1;
			if (mid + 1 < n)
				merge(a, i, mid, mid + 1, min(i + step - 1, n - 1));
		}
	}
}
int main() {
	int a[] = { 1 ,4 ,2, 12, 5, 8 ,63 ,9 ,21, 32 };
	mergeSort2(a, 10);
	for (int i = 0;i < 10;i++)
		cout << a[i] << " ";
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 