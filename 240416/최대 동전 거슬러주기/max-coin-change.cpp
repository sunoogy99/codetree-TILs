// https://www.codetree.ai/missions/2/problems/max-coin-change/description
// 최대 동전 거슬러주기
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int n, m;
int coin[101];
int dp[10001];

void initialize() {
	for (int i = 1; i <= m; i++) {
		dp[i] = INT_MIN;
	}

	dp[0] = 0;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	initialize();

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= coin[j]) {
				// i - coin[j] 값 갱신이 없는 경우
				// 해당 금액을 만드는 동전 조합이 없음을 의미
				if (i - coin[j] == INT_MIN)
					continue;

				dp[i] = max(dp[i], dp[i - coin[j]] + 1);
			}
		}
	}

	int ans = dp[m];
	if (ans == INT_MIN)
		ans = -1;
	
	cout << ans;
	return 0;
}