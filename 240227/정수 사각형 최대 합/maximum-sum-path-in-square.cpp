#include <iostream>
using namespace std;

int n;
long long arr[101][101];
long long ans[101][101];

int max(int a, int b) {
	return a > b ? a : b;
}

//long long dp(int r, int c) {
//	if (r > 0 && c > 0) {
//		ans[r][c] = max(dp(r - 1, c), dp(r, c - 1)) + arr[r][c];
//		return ans[r][c];
//	}
//	else return 0;
//}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];

			ans[i][j] = arr[i][j] + max(ans[i - 1][j], ans[i][j - 1]);
		}
	}

	cout << ans[n][n];
	return 0;
}