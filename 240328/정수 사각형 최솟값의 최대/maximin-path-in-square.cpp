// https://www.codetree.ai/missions/2/problems/maximin-path-in-square/description
// 지나가면서 최솟값 갱신하고, 도달하면 집어넣기
#include <iostream>
#include <climits>
#include <vector> 
using namespace std;

int n;
int arr[101][101];
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
bool visited[101][101];
// 최솟값 넣을거고, 여기서 최대인 걸 출력하면 됨
vector<int> min_list;

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool canGo(int x, int y) {
	if (!InRange(x, y))
		return false;
	else if (visited[x][y])
		return false;
	return true;
}

// 모든 경로 탐색해야 함
// 가는 경로에 최솟값 찾을 거고, 재귀함수 특징 이용해서 풀거임
// min_val을 pass by value로 전해주면, 함수 스택에서 나오면서
// 이전에 저장된 값으로 돌아감
// pass by reference로 하면, 값 자체가 바껴서 다른 결과 나옴
void dfs(int cur_x, int cur_y, int min_val) {
	visited[cur_x][cur_y] = true;

	if (arr[cur_x][cur_y] < min_val) {
		min_val = arr[cur_x][cur_y];
	}

	if (cur_x == n - 1 && cur_y == n - 1) {
		min_list.push_back(min_val);
	}

	for (int i = 0; i < 2; i++) {
		int new_x = cur_x + dx[i];
		int new_y = cur_y + dy[i];

		if (canGo(new_x, new_y)) {
			dfs(new_x, new_y, min_val);
			visited[new_x][new_y] = false;
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int min_val = INT_MAX;
	dfs(0, 0, min_val);

	int max_val = INT_MIN;
	for (auto& num : min_list) {
		if (num > max_val)
			max_val = num;
	}

	cout << max_val;
	return 0;
}