#include <iostream>
using namespace std;

int n;
int grid[101][101];
bool visited[101][101];

int oCnt;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool inRange(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= n;
}

bool canGo(int x, int y) {
	if (!inRange(x, y)) return false;
	else if (visited[x][y] || !grid[x][y]) return false;
	else return true;
}

void dfs(int x, int y) {
	visited[x][y] = true;
	oCnt++;

	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (canGo(newX, newY)) {
			dfs(newX, newY);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (canGo(i, j)) {
				dfs(i, j);
				if (oCnt >= 3) res += oCnt;
				oCnt = 0;
			}
		}
	}

	cout << res << '\n';
	return 0;
}