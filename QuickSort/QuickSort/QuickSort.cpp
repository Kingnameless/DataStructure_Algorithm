#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int partition(int a[], int left, int right) {
	int temp = a[left];//�ɲ��������Ԫ��������ŵ�����:p=rand(),swap(a[left],a[p])
	while (left < right) {
		while (left<right&&a[right]>temp) right--;
		a[left] = a[right];
		while (left < right&&a[left] <= temp) left++;
		a[right] = a[left];
	}
	a[left] = temp;
	return left;
}
void QuickSort(int a[], int left, int right) {
	if (left < right) {
		int pos = partition(a, left, right);
		QuickSort(a, left, pos - 1);QuickSort(a, pos + 1, right);
	}
}
int main() {  
	int a[] = { 4,2,7,10,9,6,1,23,15,31 };
	QuickSort(a, 0, 9);
	for (int i = 0;i < 10;i++)
		cout << a[i] << " ";
	return 0;
}

/*
�״�㣺
�ջ�
*/
//δ��ɣ�B1048 