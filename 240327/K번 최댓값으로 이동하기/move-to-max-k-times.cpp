// https://www.codetree.ai/missions/2/problems/move-to-max-k-times/description
// 1회차 40분 가량 소요
#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;

int n, k, r, c;	// r, c에는 출발 위치가 계속 갱신될 거임
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int grid[101][101];
bool visited[101][101];
queue<pair<int, int>> q;		// 고정된 출발 위치 기준 BFS 수행할 큐
queue<pair<int, int>> start;	// BFS 수행하며 발견한 최댓갑인 칸 좌표 저장 큐

bool InRange(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

bool canGo(int x, int y) {
	if (!InRange(x, y))
		return false;
	// 출발점에 있는 값보다 큰 값으로는 이동할 수 없음
	else if (visited[x][y] || grid[x][y] >= grid[r][c])
		return false;
	else
		return true;
}

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}

	cin >> r >> c;
	start.push(make_pair(r, c));
	
	// max_r, max_c에는 시작 위치 값보다 작은 수 중 최대인 칸의 좌표 저장
	int max_r = r;
	int max_c = c;
	
	while (!start.empty() && k > 0) {
		// 현재 칸보다 작은 값들 중 최댓값 저장할 변수
		// 현재 칸 값 이상인 칸은 canGo 함수 내부에서 이미 걸러짐
		int max_val = INT_MIN;
		
		r = start.front().first;
		c = start.front().second;
		start.pop();
		memset(visited, false, sizeof(visited));

		q.push(make_pair(r, c));
		visited[r][c] = true;

		// 출발 위치 r, c에 대해 BFS 수행
		while (!q.empty()) {
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int new_x = cur_x + dx[i];
				int new_y = cur_y + dy[i];

				if (canGo(new_x, new_y)) {
					// 방문한 칸에 대해 최댓값인 경우 좌표 확인하여 갱신
					if (grid[new_x][new_y] > max_val) {
						max_val = grid[new_x][new_y];
						max_r = new_x;
						max_c = new_y;
					}
					// 최댓값과 같을 때는 행 번호가 더 작은 걸로 갱신 
					else if (grid[new_x][new_y] == max_val) {
						if (new_x < max_r) {
							max_r = new_x;
							max_c = new_y;
						}
						// 행 번호까지 같으면 열 번호가 더 작은 걸로 갱신
						else if (new_x == max_r && new_y < max_c) {
							max_c = new_y;
						}
					}

					visited[new_x][new_y] = true;
					q.push(make_pair(new_x, new_y));
				}
			}
		}

		// 다음 시작 위치가 현재 시작 위치랑 같은 경우 = 이동할 지점 없음
		if (max_r == r && max_c == c)
			break;
		
		// 최종적으로 갱신된 최댓값 칸을 새로운 시작 위치로 지정
		start.push(make_pair(max_r, max_c));
		k--;
	}

	cout << max_r << ' ' << max_c << '\n';

	return 0;
}