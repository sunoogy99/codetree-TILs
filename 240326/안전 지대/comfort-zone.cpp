// https://www.codetree.ai/missions/2/problems/comfort-zone/description
#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

int n, m, k;
int max_region;
int max_val = INT_MIN;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int town[51][51];
bool visited[51][51];
vector<int> safe_region;

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool canGo(int x, int y) {
	if (!InRange(x, y))
		return false;
	else if (town[x][y] <= k || visited[x][y])
		return false;
	else
		return true;
}

void dfs(int cur_x, int cur_y) {
	visited[cur_x][cur_y] = true;

	for (int i = 0; i < 4; i++) {
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
			cin >> town[i][j];
		}
	}

	for (k = 1; k <= 100; k++) {
		int cnt = 0;
		// visited 2차원 배열 초기화 (cstring 필요)
		memset(visited, false, sizeof(visited));

		// DFS 간선 없는 경우도 탐색하는 방법
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// 새로운 정점에 들어갈 때 마을 높이와 방문 여부 체크 필요
				// dfs를 수행하고 마치면, dfs 수행 지역 만큼이 하나의 그룹(cnt)이 됨
				if (town[i][j] > k && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		safe_region.push_back(cnt);
	}

	for (int i = 0; i < safe_region.size(); i++) {
		if (safe_region[i] > max_val) {
			max_region = i + 1;
			max_val = safe_region[i];
		}
	}

	cout << max_region << ' ' << max_val << '\n';
	return 0;
}