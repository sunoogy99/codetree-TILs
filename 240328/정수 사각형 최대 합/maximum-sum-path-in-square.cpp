#include <iostream>
#include <cstdlib>
using namespace std;

int n;
int arr[101][101];
int dp[101][101];

bool InRange(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < n;
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + arr[i][0];
		dp[0][i] = dp[0][i - 1] + arr[0][i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[n - 1][n - 1];

	return 0;
}