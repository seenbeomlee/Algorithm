// just bit-calculation in c++

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include <algorithm> // sort
#include <cmath>     // floor

using namespace std;

int main() {
	string A, B;
	cin >> A >> B;

	int* arrA = new int[A.length()];
	int* arrB = new int[B.length()];

	for (int i = 0; i < A.length(); i++) {
		arrA[i] = A[i] - '0';
		arrB[i] = B[i] - '0';
	}

	for (int i = 0; i < A.length(); i++) {
		cout << (arrA[i] == 1 && arrB[i] == 1) ? 1 : 0;
	}
	cout << endl;
	for (int i = 0; i < A.length(); i++) {
		cout << (arrA[i] == 1 || arrB[i] == 1) ? 1 : 0;
	}
	cout << endl;
	for (int i = 0; i < A.length(); i++) {
		cout << (arrA[i] != arrB[i]) ? 1 : 0;
	}
	cout << endl;
	for (int i = 0; i < A.length(); i++) {
		cout << !arrA[i];
	}
	cout << endl;
	for (int i = 0; i < A.length(); i++) {
		cout << !arrB[i];
	}
}