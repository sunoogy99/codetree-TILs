#include <iostream>
using namespace std;

int n;
long long cnt;
long long arr[1001];

long long dp(int num) {
	if (num == 2 || num == 3) {
		return arr[num];
	}
	else if (num < 0) {
		return 0;
	}
	else {
		if (!arr[num]) {
			arr[num] = dp(num - 2) + dp(num - 3);
		}
		return arr[num];
	}
}

int main() {
	cin >> n;

	arr[2] = 1;
	arr[3] = 1;

	long long ans = dp(n);
	ans %= 10007;
	cout << ans;
	return 0;
}