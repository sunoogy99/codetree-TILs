// https://www.codetree.ai/missions/2/problems/1-2-5-plus/description
// 1,2,5 더하기
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int num[3] = { 1,2,5 };
int dp[1001];

int main() {
	cin >> n;

	// 1,2,5는 자기 숫자에 의해 만들어지는 경우 1가지는 무조건 존재함
	for (int i = 0; i < 3; i++)
		dp[num[i]] = 1;

	// 더해지는 순서가 다르면 다른 조합임
	// 이전까지의 합을 만드는 경우의 수들을 dp[i]에 계속 더해주면 된다.
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i >= num[j]) {
				dp[i] += dp[i - num[j]];
				dp[i] %= 10007;
			}
		}
	}

	cout << dp[n];
	return 0;
}