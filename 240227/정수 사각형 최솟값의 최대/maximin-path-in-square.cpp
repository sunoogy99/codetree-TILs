#include <iostream>
#include <limits.h>
using namespace std;

int n;
pair<int, int> track[101][101];
long long arr[101][101];
long long ans[101][101];

long long max(long long a, long long b) {
	return a > b ? a : b;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (ans[i - 1][j] > ans[i][j - 1]) {
				ans[i][j] = arr[i][j] + ans[i - 1][j];
				track[i][j] = make_pair(i - 1, j);
			}
			else {
				ans[i][j] = arr[i][j] + ans[i][j - 1];
				track[i][j] = make_pair(i, j - 1);
			}
		}
	}

	long long min_val = LLONG_MAX;
	int r = n, c = n;
	while (r > 0 && c > 0) {
		if (arr[r][c] < min_val) {
			min_val = arr[r][c];
		}

		pair<int, int> tmp = track[r][c];
		r = tmp.first;
		c = tmp.second;
		/* 
			r = track[r][c].first; 
			c = track[r][c].second;
			이렇게 선언하면, c 할당할 때 r 값이 바뀌어서 결과가 완전 달라짐
		*/
	}

	cout << min_val;
}