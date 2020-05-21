#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	
	cin >> t;

	int* arr = new int[t];
	int* dp = new int[t];

	for (int i = 0; i < t; i++) cin >> arr[i];

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for(int i = 3; i < t; i++) dp[i] = max( (arr[i]+arr[i - 1]+dp[i - 3]), (arr[i]+dp[i - 2]) );

	cout << dp[t-1] << endl;

	delete[] arr;
	delete[] dp;
}