#include <iostream>
using namespace std;

int n, m, k;

int parent[100001];
int height[100001];

int Find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return;

	if (height[x] < height[y]) {
		parent[x] = y;
	}
	else if (height[x] > height[y]) {
		parent[y] = x;
	}
	else {
		parent[y] = x;
		height[x]++;
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		Union(x, y);
	}

	int x, y;
	cin >> x >> y;
	int xParent = Find(x);
	int yParent = Find(y);

	if (xParent == yParent) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}

	return 0;
}