#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

int min_val = INT_MAX;
int arr[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int total = 0;
	
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			for (int k = j + 1; k < 6; k++) {
				int sum1 = arr[i] + arr[j] + arr[k];
				int sum2 = total - sum1;
				int diff = abs(sum1 - sum2);
				if (diff < min_val) {
					min_val = diff;
				}
			}
		}
	}

	cout << min_val << "\n";

	return 0;
}