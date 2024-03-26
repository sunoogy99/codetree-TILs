// https://www.codetree.ai/missions/2/problems/seperate-village/description
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[26][26];

vector<int> town_size;

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool canGo(int x, int y) {
	if (!InRange(x, y))
		return false;
	else if (grid[x][y] == 0 || visited[x][y])
		return false;
	else
		return true;
}

void swap(int x, int y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

//	<파라미터 cnt를 참조자로 넘겨주는 이유>
//	재귀함수 내부에서 참조 변수 연산 수행 시에 대상 변수도 같이 변경된다.
//	참조자로 넘겨주지 않으면 전달된 값만 복사하는 것이므로 실제 값을 변경하는 것이 아니다. 
//	(방문 노드 수 0 출력됨)
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
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			if (grid[i][j] != 0 && !visited[i][j]) {
				dfs(i, j, cnt);
				// dfs 탐색 결과 몇 개의 노드를 탐색했는지 벡터에 저장
				town_size.push_back(cnt);
			}
		}
	}

	sort(town_size.begin(), town_size.end());

	cout << town_size.size() << '\n';

	for (auto& num : town_size)
		cout << num << '\n';

	return 0;
}