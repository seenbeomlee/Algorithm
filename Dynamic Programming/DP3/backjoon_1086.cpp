#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include <algorithm> // sort
#include <cmath>     // floor

using namespace std;

int uclid_func(int p, int q) {
	if (q == 0) return p;
	return uclid_func(q, p % q);
}

int main() {
	int N, K;
	vector<int> list;
	vector<long long> res_list;
	long long res = 0;

	scanf("%d", &N);

	int input;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		list.push_back(input);
	}

	scanf("%d", &K);

	sort(list.begin(), list.end());

	do {
		string now = "";
		for (int i = 0; i < list.size(); i++) {
			now += to_string(list[i]);
		}
		res_list.push_back(stoll(now));
	} while (next_permutation(list.begin(), list.end()));

	res_list.erase(unique(res_list.begin(), res_list.end()), res_list.end());

	for (int i = 0; i < res_list.size(); i++) cout << res_list[i] << endl;

	for (int i = 0; i < res_list.size(); i++) {
		if (res_list[i] % K == 0) {
			res++;
		}
	}

	int max_value = uclid_func(res, res_list.size());

	printf("%lld/%d\n", res / max_value, res_list.size() / max_value);
}