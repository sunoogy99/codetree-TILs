#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> tree;
vector<bool> alive; // 노드 제거 후 살아 있는 정점 인덱스 기록
queue<int> delq; // 삭제할 정점을 저장하는 큐

int main() {
	cin >> n;

	tree.resize(n);
	alive.resize(n, true);

	int par; // 부모 노드 번호
	for (int i = 0; i < n; i++) {
		cin >> par;

		if (par == -1) continue; // 루트 노드인 경우, 넘어가기
		tree[par].push_back(i);
	}

	int delNode;
	cin >> delNode;

	delq.push(delNode);

	while (!delq.empty()) {
		int dNode = delq.front();
		delq.pop();
		alive[dNode] = false; // 탐색 가능한 노드에서 현재 정점 삭제

		for (int c : tree[dNode]) {
			delq.push(c);
		}
	}

	int leafCnt = 0;
	for (int i = 0; i < n; i++) {
		if (alive[i] && tree[i].size() == 0)
			leafCnt++;
	}

	cout << leafCnt;
	return 0;
}