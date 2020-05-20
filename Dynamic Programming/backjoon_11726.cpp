#include<iostream>
int DP[1001];

int find(int n) {
	if (DP[n] != 0) return DP[n];
	else return DP[n] = (find(n - 1) + find(n - 2)) % 10007;
}

int main() {
	int n;
	std::cin >> n;
	DP[1] = 1;
	DP[2] = 2;
	std::cout << find(n);
	return 0;
}