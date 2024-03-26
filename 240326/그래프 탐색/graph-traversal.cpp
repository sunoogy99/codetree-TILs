// https://www.codetree.ai/missions/2/problems/graph-traversal/description
#include <iostream>
using namespace std;

int n, m, cnt;
int graph[1001][1001];
bool visited[1001];

void dfs(int vertex) {
	for (int i = 1; i <= n; i++) {
		if (graph[vertex][i] && !visited[i]) {
			visited[i] = true;
			cnt++;
			dfs(i);
		}
	}
}

int main() {
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a][b] = 1, graph[b][a] = 1;
	}

	visited[1] = true;
	dfs(1);

	cout << cnt << '\n';
	return 0;
}