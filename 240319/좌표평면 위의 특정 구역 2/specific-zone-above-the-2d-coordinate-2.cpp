#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, ans = INT_MAX;
int pos[101][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> pos[i][0] >> pos[i][1];
	}

	for (int i = 1; i <= n; i++) {
		int minX = INT_MAX, minY = INT_MAX;
		int maxX = INT_MIN, maxY = INT_MIN;

		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (pos[j][0] < minX) minX = pos[j][0];
			if (pos[j][1] < minY) minY = pos[j][1];
			if (pos[j][0] > maxX) maxX = pos[j][0];
			if (pos[j][1] > maxY) maxY = pos[j][1];
		}

		int area = (maxX - minX) * (maxY - minY);
		ans = min(ans, area);
	}

	cout << ans << '\n';
	return 0;
}