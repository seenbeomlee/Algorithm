#include<iostream>
#include<algorithm>
using namespace std;
int DP[1000000];

int find(long long X) {
	int a = 987654321;
	int b = 987654231;
	int c = 987654321;

	if (X == 1) return 0;
	if (DP[X] != 0) return DP[X];

	if (X % 3 == 0) a = find(X / 3) + 1;
	if (X % 2 == 0) b = find(X / 2) + 1;
	
	c = find(X - 1) + 1;

	return DP[X] = min(min(a, b), c);
}

int main() {
	int input;
	cin >> input;
	cout << find(input) << endl;
}