#include<iostream>
using namespace std;
int DP[20];

int find(int n) {
	if (n == 1) return DP[1] = 1;
	if (n == 2) return DP[2] = 2;
	if (n == 3) return DP[3] = 4;

	return DP[n] = find(n - 1) + find(n - 2) + find(n - 3);
}

int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << find(n) << endl;
	}
	return 0;
}