// https://www.codetree.ai/missions/2/problems/puyo-puyo/description
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;

// 간과할 수도 있는 내용
// 같은 번호 상에서 터지는 블록 개수가 여러 개일 수 있다.

int n, k;
int max_val = INT_MIN;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int grid[101][101];
bool visited[101][101];
vector<int> block[101];

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool canGo(int x, int y) {
	if (!InRange(x, y))
		return false;
	else if (grid[x][y] != k || visited[x][y])
		return false;
	else
		return true;
}

void dfs(int cur_x, int cur_y, int& cnt) {
	visited[cur_x][cur_y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int new_x = cur_x + dx[i];
		int new_y = cur_y + dy[i];

		if (canGo(new_x, new_y)) {
			dfs(new_x, new_y, cnt);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			// 최대 번호가 몇인지 저장
			if (grid[i][j] > max_val) 
				max_val = grid[i][j];
		}
	}

	for (k = 1; k <= max_val; k++) {
		// cnt: 연결된 블록 개수 저장
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				/* 
					DFS 탐색 가능한 경로 조건
					1. 현재 탐색하는 숫자와 같은 값이어야 함
					2. 방문하지 않은 노드여야 함
				*/
				if (grid[i][j] == k && !visited[i][j]) {
					dfs(i, j, cnt);
					/*
						cnt 갱신 이유
						k와 같은 값에 대해 dfs 탐색 수행한다고 할 때,
						연결되지 않은 블럭도 존재할 수 있음
						따라서 cnt 값은 dfs를 마치고 나왔을 때 0으로 다시 초기화 해야 함
					*/
					block[k].push_back(cnt);
					cnt = 0;
				}
			}
		}

	}

	// pop_cnt : 터지는 블럭 개수
	// max_cnt : 터지는 블럭 중 가장 큰 블럭 크기
	int pop_cnt = 0;
	int max_cnt = INT_MIN;

	for (int i = 1; i <= max_val; i++) {
		for (auto& num : block[i]) {
			if (num >= 4)
				pop_cnt++;
			if (num > max_cnt)
				max_cnt = num;
		}
	}

	cout << pop_cnt << ' ' << max_cnt << '\n';
	return 0;
}