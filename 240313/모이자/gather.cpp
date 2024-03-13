#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

int n;
int arr[101];
int min_val = INT_MAX;

int main() {
	cin >> n;


	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		int cum_sum = 0;

		for (int j = 1; j <= n; j++) {
			cum_sum += abs(i - j) * arr[j];
		}

		if (cum_sum < min_val) {
			min_val = cum_sum;
		}
	}

	cout << min_val << endl;

	return 0;
}