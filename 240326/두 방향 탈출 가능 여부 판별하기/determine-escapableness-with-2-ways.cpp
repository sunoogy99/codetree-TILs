// https://www.codetree.ai/missions/2/problems/determine-escapableness-with-2-ways/description
#include <iostream>
using namespace std;

int n, m;
int grid[101][101];
bool visited[101][101];

int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool canGo(int x, int y) {
	if (!InRange(x, y))
		return false;
	else if (visited[x][y] || grid[x][y] == 0)
		return false;
	else 
		return true;
}

void dfs(int cur_x, int cur_y) {
	visited[cur_x][cur_y] = true;
	for (int i = 0; i < 2; i++) {
		int new_x = cur_x + dx[i];
		int new_y = cur_y + dy[i];

		if (canGo(new_x, new_y)) {
			dfs(new_x, new_y);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	dfs(0, 0);
	
	if (visited[n - 1][m - 1])
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

	return 0;
}