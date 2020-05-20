#include<iostream>
using namespace std;

int DP_1[41];
int DP_0[41];

int cal_0(int n) {
	if (DP_0[n] != 0) return DP_0[n];

	if (n == 0) return DP_0[0] = 1;
	else if (n == 1) return DP_0[1] = 0;

	else return DP_0[n] = cal_0(n - 1) + cal_0(n - 2);
}

int cal_1(int n) {
	if (DP_1[n] != 0) return DP_1[n];

	if (n == 0) return DP_1[0] = 0;
	else if (n == 1) return DP_1[1] = 1;

	else return DP_1[n] = cal_1(n - 1) + cal_1(n - 2);
}

void find(int n) {
	cout << cal_0(n) << " ";;
	cout << cal_1(n) << endl;
}

int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		find(n);
	}
}