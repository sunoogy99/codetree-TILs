#include <iostream>
using namespace std;

int n, max_cnt;
int arr[21][21];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - 2; j++) {
			max_cnt = max(max_cnt, arr[i][j] + arr[i][j + 1] + arr[i][j + 2]);
		}
	}

	cout << max_cnt << endl;
}