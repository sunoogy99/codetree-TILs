// https://www.codetree.ai/missions/2/problems/the-sum-of-the-subsequences-is-m/description
// 부분 수열의 합이 m
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n, m;
int arr[101];
int dp[10001];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	// memset(dp, INT_MAX, sizeof(dp)); -> 이거 왜 안 되는지 아직 못 찾음..
	for (int i = 1; i <= m; i++) {
		dp[i] = INT_MAX;
	}
	
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (j >= arr[i]) {
				if (dp[j - arr[i]] == INT_MAX)
					continue;

				// INT_MAX인 경우는 위에서 거름
				// Overflow 위에서 걸러짐
				dp[j] = min(dp[j], dp[j - arr[i]] + 1);
			}
		}
	}

	int ans = dp[m];
	if (dp[m] == INT_MAX)
		ans = -1;
	
	cout << ans;
	return 0;
}