#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {

	int dp[1000][3];
	int arr[1000][3];

	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	
	for (int i = 1; i < t; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	long long RESULT = min(min(dp[t - 1][0], dp[t - 1][1]), dp[t - 1][2]);

	cout << RESULT << endl;

	return 0;
}