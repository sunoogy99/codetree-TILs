#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int n;
int** arr;
int min_val = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	arr = new int*[n];

	for (int i = 0; i < n; i++) {
		arr[i] = new int[2];
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int diffX = arr[j][0] - arr[i][0];
			int diffY = arr[j][1] - arr[i][1];
			int square = pow(diffX, 2) + pow(diffY, 2);
			if (square < min_val) min_val = square;
		}
	}

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}

	delete[] arr;

	cout << min_val << "\n";
	return 0;
}