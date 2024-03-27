// https://www.codetree.ai/missions/2/problems/determine-escapableness-with-4-ways/description
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int grid[101][101];			// 인접 행렬 기반 그래프
bool visited[101][101]; 
queue<pair<int, int>> q;	// 노드 = 좌표 = pair<int, int>

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

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	q.push(make_pair(0, 0));
	visited[0][0] = true;

	// BFS 수행 (반복문)
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];

			if (canGo(new_x, new_y)) {
				visited[new_x][new_y] = true;
				q.push(make_pair(new_x, new_y));
			}
		}
	}

	if (visited[n - 1][m - 1])
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

	return 0;
}