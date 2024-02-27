#include <iostream>
using namespace std;

int n;
long long dp[46];

long long fib(int num) {
	if (num <= 2) {
		return 1;
	}
	else {
		if (dp[num] != 0) {
			return dp[num - 1] + dp[num - 2];
		}
		else {
			dp[num] = fib(num - 1) + fib(num - 2);
			return dp[num];
		}
	}
}

int main() {
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;

	cout << fib(n);
	return 0;
}