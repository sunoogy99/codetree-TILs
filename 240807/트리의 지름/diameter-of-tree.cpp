#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<vector<pair<int, int>>> tree; // 연결된 정점, 가중치 저장
bool visited[100001];

int dist;

void dfs(int x) {
	visited[x] = true;
	
	int maxC = -1;
	int maxD = 0;
	for (pair<int, int> c : tree[x]) {
		if (!visited[c.first] && c.second > maxD) {
			maxC = c.first;
			maxD = c.second;
		}
	}

	if (maxC != -1) {
		dist += maxD;
		dfs(maxC);
	}
}

int main() {
	cin >> n;

	tree.resize(n + 1);

	int a, b, w;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> w;
		tree[a].push_back(make_pair(b, w));
		tree[b].push_back(make_pair(a, w));
	}

	int maxDist = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof visited);
		dfs(i);

		if (dist > maxDist) {
			maxDist = dist;
		}

		dist = 0;
	}

	cout << maxDist << '\n';
	return 0;
}