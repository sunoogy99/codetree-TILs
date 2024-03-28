// https://www.codetree.ai/missions/2/problems/maximin-path-in-square/description
#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

int n;
int arr[101][101];
int dp[101][101];

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}

	int min_val = INT_MAX;
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][0], arr[i][0]);
		dp[0][i] = min(dp[0][i - 1], arr[0][i]);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = min(max(dp[i - 1][j], dp[i][j - 1]), arr[i][j]);
		}
	}

	cout << dp[n - 1][n - 1];
	return 0;
}