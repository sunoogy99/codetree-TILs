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
			arr[num] = dp(num - 1) % 10007 + dp(num - 2) % 10007;
			arr[num] %= 10007;
		}
		return arr[num];
	}
}

int main() {
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	cout << dp(n);
	return 0;
}