#include <iostream>
#include <climits>
using namespace std;

int n, k;
int max_val = INT_MIN;
char pos[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	int p;
	char val;
	for (int i = 1; i <= n; i++) {
		cin >> p >> val;
		pos[p] = val;
	}

	for (int i = 1; i <= 10001; i++) {
		int point = 0;
		
		for (int j = 0; j <= k; j++) {
			if (pos[i + j] == 'G') {
				point += 1;
			}
			else if (pos[i + j] == 'H') {
				point += 2;
			}
		}

		if (point > max_val) {
			max_val = point;
		}
	}

	cout << max_val << '\n';
	return 0;
}