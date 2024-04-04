// https://www.codetree.ai/missions/2/problems/maximum-number-of-jumps/description
// 최대 점프 횟수
#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int max_val = INT_MIN;
int arr[1001];
int dp[1001];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));
	dp[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			// 출발점으로부터 점프 가능한 지점이므로 도중에 끊기면
			// 해당 부분은 출발점에서 도달 가능한 지점이 아님
			// dp[j] != -1 조건 추가함
			if (j + arr[j] >= i && dp[j] != -1) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		max_val = max(max_val, dp[i]);
	}

	cout << max_val;
	return 0;
}