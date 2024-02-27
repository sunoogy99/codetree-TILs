#include <iostream>
using namespace std;

int n;
long long arr[101][101];
long long ans[101][101];

long long min(long long a, long long b) {
	if (a == 0) return b;
	else if (b == 0) return a;
	else return a < b ? a : b;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) {
			ans[i][j] = arr[i][j] + min(ans[i - 1][j], ans[i][j + 1]);
		}
	}

	cout << ans[n][1];
	return 0;
}