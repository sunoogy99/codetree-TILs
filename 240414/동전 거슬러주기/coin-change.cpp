// https://www.codetree.ai/missions/2/problems/coin-change/description
// 동전 거슬러주기
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int coin[101];
int dp[10001];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	// INT_MAX로 초기화하면 INT_MAX + 1이 최솟값으로 바뀌어 버림
	// overflow 문제로 다른 방식으로 초기화함 
	// memset 안 먹는 거는 알아봐야 함 (이상한 값으로 초기화됨..)
	for (int i = 1; i <= m; i++) {
		dp[i] = 99999;
	}

	dp[0] = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= coin[j]) {
				if (dp[i - coin[j]] == 99999) 
					continue;

				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
			}
		}
	}

	int ans = dp[m];
	if (ans == 99999)
		ans = -1;
	
	cout << ans;

	return 0;
}