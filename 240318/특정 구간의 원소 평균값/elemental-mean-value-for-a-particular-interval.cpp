#include <iostream>
using namespace std;

int n, ans;
double arr[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			double part_sum = 0;

			for (int k = i; k <= j; k++) {
				part_sum += arr[k];
			}

			double mean = part_sum / (j - i + 1);

			for (int k = i; k <= j; k++) {
				if (mean == arr[k]) {
					ans++;
					break;
				}
			}
		}
	}

	cout << ans << "\n";
	return 0;
}