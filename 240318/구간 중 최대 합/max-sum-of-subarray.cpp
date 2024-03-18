#include <iostream>
#include <climits>
using namespace std;

int n, k, part_sum;
int arr[101];
int max_val = INT_MIN;

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		if (i > k - 1) {
			part_sum += arr[i];
			part_sum -= arr[i - k];

			if (part_sum > max_val) {
				max_val = part_sum;
			}
		}
		else {
			part_sum += arr[i];
		}
	}

	cout << max_val << endl;
	return 0;
}