#include <iostream>
using namespace std;

int n, cnt;
int arr[101];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] <= arr[j]) {
				for (int k = j + 1; k < n; k++) {
					if (arr[j] <= arr[k]) cnt++;
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}