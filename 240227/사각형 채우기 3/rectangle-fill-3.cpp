#include <iostream>
using namespace std;

int n;
long long arr[1001];

long long dp(int num) {
	if (num <= 2) {
		return arr[num];
	}
	else {
		if (!arr[num]) {
			arr[num] = dp(num - 1) % 1'000'000'007 * 2 + dp(num - 2) % 1'000'000'007 * 3 + 2;
			arr[num] %= 1'000'000'007;
		}
		return arr[num];
	}
}

int main() {
	cin >> n;

	arr[1] = 2;
	arr[2] = 7;

	cout << dp(n);

	return 0;
}