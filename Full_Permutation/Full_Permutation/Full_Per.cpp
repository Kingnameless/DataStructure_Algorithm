#include<stdio.h>
#include<iostream>
using namespace std;
const int maxnum = 100;
bool p[maxnum] = { 0 };int Fp[maxnum] = { 0 };
int n;
void Full_Per(int pos) {
	if (pos == n + 1) {
		for (int i = 1;i <= n;i++)
			cout << Fp[i];
		cout << endl;
	}
	for (int i = 1;i <= n;i++) {
		if (!p[i]) {
			Fp[pos] = i;p[i] = true;
			Full_Per(pos + 1);
			p[i] = false;
		}
	}
}
//全排列应用举例，n皇后问题
int num = 0;
void N_Q(int pos) {
	if (pos == n + 1)
		num++;
	for (int i = 1;i <= n;i++) {
		if (!p[i]) {
			bool pla = true;
			for(int j=1;j<pos;j++)
				if (abs(pos - j) == abs(i - Fp[j])) {
					pla = false;
					break;
				}
			if (pla) {
				Fp[pos] = i;p[i] = true;
				N_Q(pos + 1);p[i] = false;
			}
		}
	}
}
int main() {
	n = 8;
	N_Q(1);
	cout << "n:" << n << " num:" << num << endl;
	return 0;
}
